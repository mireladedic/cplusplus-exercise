
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <iomanip>
#include <algorithm>
// IMA MALO CURENJE MEMORIJE

class Tim {
    char ime_tima[20];
    int broj_odigranih,broj_pobjeda,broj_nerijesenih,broj_poraza,broj_datih,broj_primljenih,broj_poena;
public:
        Tim(const char ime[]);
        void ObradiUtakmicu(int broj_datih, int broj_primljenih);
        const char *DajImeTima() const;
        int DajBrojPoena() const;
        int DajGolRazliku() const;
        void IspisiPodatke() const;
};

Tim::Tim(const char ime[]):broj_odigranih(0),broj_pobjeda(0),broj_nerijesenih(0),broj_poraza(0),broj_datih(0),broj_primljenih(0),broj_poena(0){
    if(std::strlen(ime) < 1 || std::strlen(ime) > 19) throw std::range_error("Predugacko ime!\n");
    std::strcpy(Tim::ime_tima,ime);
}

void Tim::ObradiUtakmicu(int broj_datih,int broj_primljenih){
    if(broj_datih < 0 || broj_primljenih < 0) throw std::range_error("Negativan parametar!\n");

    if(broj_datih > broj_primljenih){
        broj_pobjeda++;
        broj_poena += 3;
    }else if(broj_datih == broj_primljenih){
        broj_nerijesenih++;
        broj_poena += 1;
    }else{
        broj_poraza++;
    }

    broj_odigranih++;
    Tim::broj_datih = broj_datih;
    Tim::broj_primljenih = broj_primljenih;

}

const char *Tim::DajImeTima() const{
    return ime_tima;
}

int Tim::DajGolRazliku() const{
    if(broj_datih > broj_primljenih) return (broj_datih - broj_primljenih);
    return (broj_primljenih - broj_datih);
}

int Tim::DajBrojPoena()const{ return broj_poena;}

void Tim::IspisiPodatke() const{
    std::cout<<std::setw(20)<<std::left<<ime_tima<<" | ";
    std::cout<<std::setw(4)<<std::right<<broj_odigranih<< " | ";
    std::cout<<std::setw(4)<<std::right<< broj_pobjeda<<" | ";
    std::cout<<std::setw(4)<<std::right<<broj_nerijesenih<<" | ";
    std::cout<<std::setw(4)<<std::right<< broj_poraza<<" | ";
    std::cout<<std::setw(4)<<std::right<< broj_datih<<" | ";
    std::cout<<std::setw(4)<<std::right<<broj_primljenih<<" | ";
    std::cout<<std::setw(4)<<std::right<< broj_poena<<std::endl;
}

class Liga{
   int broj_timova;
   const int max_broj_timova;
   Tim ** timovi;

   int PronadjiTim(const char *ime) const{

        for(int i = 0; i < broj_timova;i++) {
                if(std::strcmp(timovi[i]->DajImeTima(), ime) == 0) {return i;}
        }
        return -1;
    }

    static bool funkcijakriterija(const Tim *tim1,const Tim *tim2){
        if(tim1->DajBrojPoena() == tim2->DajBrojPoena()) {

            if(tim1->DajGolRazliku() == tim2->DajGolRazliku())  return tim1->DajImeTima() < tim2->DajImeTima();
            return tim1->DajGolRazliku() > tim2->DajGolRazliku();
        }
        return tim1->DajBrojPoena() > tim2-> DajBrojPoena();
    }

public:
    explicit Liga(int velicina_lige);
    explicit Liga(std::initializer_list<Tim> lista_timova);
    ~Liga();
    Liga(const Liga &l);
    Liga(Liga &&l);
    Liga &operator =(const Liga &l);
    Liga &operator =(Liga &&l);
    void DodajNoviTim(const char ime_tima[]);
    void RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2);
    void IspisiTabelu();
};
//..KONSTRUKTOR
Liga::Liga(int velicina_lige): broj_timova(0),max_broj_timova(velicina_lige),timovi(new Tim*[velicina_lige]{}){}
//...KONSTRUKTOR INICIJALIZACIJSKI
Liga::Liga(std::initializer_list<Tim> lista_timova): broj_timova(lista_timova.size()),max_broj_timova(lista_timova.size()),timovi(new Tim *[lista_timova.size()]{}){
//  std::copy(lista_timova.begin(),lista_timova.end(),timovi->DajImeTima());
    int brojac = 0;
    try{
        for(auto &x : lista_timova){
            timovi[brojac++] = new Tim(x);
        }
    }catch(...){
        for(int i = 0; i < brojac;i++) delete timovi[i];
        delete[]timovi;
    }
}
//...DESTRUKTOR
Liga::~Liga(){ for(int i = 0; i < broj_timova;i++) delete timovi[i]; delete[]timovi; }
//...KOPIRAJUCI KONSTRUKTOR KOPIJE
Liga::Liga(const Liga &l): broj_timova(l.broj_timova),max_broj_timova(l.max_broj_timova),timovi(new Tim*[l.max_broj_timova]{}){

   try{
        for(int i = 0; i < l.broj_timova;i++)
            Liga::timovi[i] = new Tim(*l.timovi[i]);
        } catch(...){
            for(int i = 0; i < l.broj_timova;i++) delete[]timovi[i];
            delete[]timovi;
            throw;
        }
}
//...POMJERAJUCI KONSTRUTOR KOPIJE
Liga:: Liga(Liga &&l): broj_timova(l.broj_timova), max_broj_timova(l.max_broj_timova),timovi(l.timovi){
    l.timovi = nullptr;
    l.broj_timova = 0;
}

//...KOPIRAJUCI OPERATOR DODJELE - OVO SI POGRESNO URADILA NA ISPITU
Liga &Liga::operator=(const Liga &l){
    if(l.max_broj_timova !=  max_broj_timova) throw std::logic_error("Nesaglasni kapaciteti liga");

    if(l.broj_timova > broj_timova){
        try{
            for(int i = broj_timova ; i < l.broj_timova;i++)
                timovi[i] = new Tim(*l.timovi[i]);
        }catch(...){
            for(int i = broj_timova; i < l.broj_timova;i++)
                {delete timovi[i]; timovi[i]= nullptr; }
            throw std::domain_error("Curenje");
        }
    }else{
        for(int i = l.broj_timova; i < broj_timova;i++)
            {delete timovi[i]; timovi[i] = nullptr;}
    }

    broj_timova  = l.broj_timova;

    //... BITNO
    try{
    for(int i = 0; i < broj_timova;i++)
        (*timovi)[i] = (*l.timovi)[i];
    }catch(...){
        std::cout<<"mem";
    }
    return *this;

}
//...OPERATOR DODJELE POMJERAJUCI
Liga &Liga::operator =(Liga &&l){
    if(l.max_broj_timova != max_broj_timova) throw std::logic_error("Nesaglasni kapaciteti liga\n");
    std::swap(Liga::broj_timova,l.broj_timova);
    std::swap(Liga::timovi,l.timovi);
    return *this;
}

void Liga::DodajNoviTim(const char ime_tima[]){

    //..DINAMICKI KREIRA OBJEKAT TIPA TIM
    //...BROJ TIMOVA U LIGI SE POVECAVA ZA JEDINICU
    //..U SLUCAJU DA JE IME PREDUGACKO BACA SE IZUZETAK
    //.. UKOLIKO SE POKUSA UPISATI TIM CIJE IME VEC POSTOJI BACA SE IZUZETAK

    if(this->broj_timova >= max_broj_timova) throw std::range_error("Liga popunjena");

    if(std::strlen(ime_tima) < 1 || std::strlen(ime_tima) > 19) throw std::range_error("Predugacko ime tima u DodajNoviTIm\n");

    for(int i = 0; i < broj_timova;i++)
    if(std::strcmp(timovi[i]->DajImeTima(),ime_tima) == 0) throw std::domain_error("Vec postoji taj tim!\n");

     Tim *tim = nullptr;
	try{
   	tim  = new Tim(ime_tima);
    timovi[this->broj_timova++] = tim;
    //std::cout << broj_timova << std::endl;
	}catch(...){
		delete tim;
		tim = nullptr;
		std::cout<<"Curenje memorije!\n";
	}
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2){
    if(rezultat_1 < 0 || rezultat_2 < 0) throw std::range_error("Neispravan broj golova");

    if(PronadjiTim(tim1) == -1 ) this->DodajNoviTim(tim1); //throw std::logic_error("Tim se ne nalazi u ligi.");}
    if(PronadjiTim(tim2) == -1){this->DodajNoviTim(tim2);}

     timovi[PronadjiTim(tim1)]->ObradiUtakmicu(rezultat_1,rezultat_2);
    timovi[PronadjiTim(tim2)]->ObradiUtakmicu(rezultat_2,rezultat_1);


}

void Liga::IspisiTabelu(){
    std::sort(timovi,timovi + broj_timova,funkcijakriterija);
    for(int i = 0; i < broj_timova;i++) timovi[i]->IspisiPodatke();
}
int main()
{
    /*
   Tim tim1("Zeljo");Tim tim2("Sarajevo");
   tim1.ObradiUtakmicu(2,3);
   tim2.ObradiUtakmicu(5,1);
   tim1.IspisiPodatke();
   std::cout<<"\n";
   tim2.IspisiPodatke();
   */

   //Liga liga(6);
  /* Tim t1("Zeljo"),t2("Sarajevo"),t3("Sloboda") , t4("Vitez"), t5("Velez") , t6("Zrinjski");
    t1.ObradiUtakmicu(3,2);
    t2.ObradiUtakmicu(3,2);
    t3.ObradiUtakmicu(3,2);
    t4.ObradiUtakmicu(3,2);
    t5.ObradiUtakmicu(3,2);
    t6.ObradiUtakmicu(3,2);

   liga.DodajNoviTim("Zeljo");
   liga.DodajNoviTim("Sarajevo");

   liga.DodajNoviTim("Sloboda");
   liga.DodajNoviTim("Vitez");

   liga.DodajNoviTim("Borac");
   liga.DodajNoviTim("Velez");

   liga.RegistrirajUtakmicu("Zeljo","Sarajevo",3,2);
   liga.RegistrirajUtakmicu("Sloboda","Vitez",1,3);
   liga.RegistrirajUtakmicu("Borac","Velez",2,1);

   liga.IspisiTabelu();


   Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};
Liga l2{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo", "FK Krupa"};

try { l1=l2; }
catch(std::logic_error e) { std::cout << e.what() << std::endl; }


Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};

try { l1.DodajNoviTim("FK Borac Banja Luka"); }
catch(std::range_error e) { std::cout << e.what() << std::endl; }

Liga l1(2);

try {
    l1.RegistrirajUtakmicu("NK Zeljeznicar", "FK Sarajevo", 1, 1);
    //l1.DodajNoviTim("Fk Borac");
   // l1.DodajN
    l1.IspisiTabelu();
}
catch(std::logic_error e) { std::cout << e.what() << std::endl; }

Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};

try { l1.DodajNoviTim("FK Borac Banja Luka"); }
catch(std::range_error e) { std::cout << e.what() << std::endl; }

Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};

try { l1.RegistrirajUtakmicu("NK Zeljeznicar", "FK Krupa", 1, 1); }
catch(std::logic_error e) { std::cout << e.what() << std::endl; }
*/
Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo", "FK Sloboda", "FK Krupa", "FK Radnik Bijeljina"};
l1.RegistrirajUtakmicu("NK Zeljeznicar", "HSK Zrinjski",2,0);
Liga l2(l1);

std::cout << "Orginalna Liga za Prvaka: " << std::endl;
l1.IspisiTabelu();
std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
l2.IspisiTabelu();

l2.RegistrirajUtakmicu("FK Krupa", "FK Sloboda",1,1);

std::cout << std::endl << "Nakon izmjene kopije: " << std::endl << std::endl;

std::cout << "Orginalna Liga za Prvaka: " << std::endl;
l1.IspisiTabelu();
std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
l2.IspisiTabelu();
    return 0;
}
