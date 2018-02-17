#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
class Datum{
    int dan,mjesec,godina;
public:
    Datum(int d,int m,int g);
    void Ispisi()const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina<<std::endl;}
};

Datum::Datum(int d,int m,int g){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if( g % 4 == 0 && (g % 100 == 0 || g %100 == 0)) broj_dana[1]++;

    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error("Nekorekran parametar klase datum\n");

    dan = d; mjesec = m; godina = g;
}

class Ucenik{
    static const int BrojPredmeta = 10;
    char ime[20],prezime[20];
    Datum datum_rodjenja;
    int ocjene[BrojPredmeta];
    double prosjek;
    bool prolaz;

public:
    Ucenik(const char ime[],const char prezime[],int d,int m,int g);
    void PostaviOcjenu(int predmet,int ocjena);
    static int DajBrojPredmeta() { return BrojPredmeta;}
    double DajProsjek()const{ return prosjek;}
    bool DaLiJeProsao() const{ return prolaz;}
    void Ispisi() const;

};

Ucenik::Ucenik(const char ime[],const char prezime[],int d,int m,int g): datum_rodjenja(d,m,g),prosjek(1),prolaz(false){
   if(std::strlen(ime) > 19 || std::strlen(prezime) > 19)
        std::domain_error("Predugacko ime ili prezime!\n");
   std::strcpy(Ucenik::ime,ime);
   std::strcpy(Ucenik::prezime,prezime);

   for(int &ocjena : ocjene) ocjena = 1;
}

void Ucenik::PostaviOcjenu(int predmet,int ocjena){
    if(ocjena < 1 || ocjena > 5) throw std::domain_error("Nekorektna ocjena.\n");
    if(predmet < 1 || predmet > BrojPredmeta) std::domain_error("Nekorekran broj predmeta.\n");
    ocjene[predmet -1] =  ocjena;
    prosjek = 1; prolaz = false;
    double suma_ocjena(0);
    for(int ocjena : ocjene){
        if(ocjena == 1) return;
        suma_ocjena += ocjena;
    }

    prosjek = suma_ocjena/BrojPredmeta;
    prolaz = true;
}

void Ucenik::Ispisi()const{
    std::cout<<"Ucenik " << ime<< " "<< prezime<< " rodjen ";
    datum_rodjenja.Ispisi();
    if(DaLiJeProsao()) std::cout<<" ima prosjek "<< std::setprecision(3)<<DajProsjek()<<std::endl;
    else
        std::cout<<" mora ponavljati razred.\n";
}

class Razred{
    const int kapacitet;
    int broj_evidentiranih;
    Ucenik ** ucenici;

    static bool BoljiProsjek(const Ucenik *u1,const Ucenik *u2){
        return (u1->DajProsjek() > u2->DajProsjek());
    }
public:

    explicit Razred(int broj_ucenika) : kapacitet(broj_ucenika),broj_evidentiranih(0),ucenici(new Ucenik*[broj_ucenika]{}){}
    ~Razred();
    Razred(const Razred &r);
    Razred &operator=(const Razred &r);
    void EvidentirajUcenika(Ucenik *ucenik);
    void UnesiNovogUcenika();
    void IspisiIzvjestaj() const;
    void SortirajUcenike(){
        std::sort(ucenici,ucenici + broj_evidentiranih,BoljiProsjek);
    }
    Razred(Razred &&r);
    Razred &operator=(Razred r);
    Razred &operator=(Razred &&r);
};
//... DESTRUKTOR
Razred::~Razred(){
    for(int i = 0; i < broj_evidentiranih; i++) delete[]ucenici[i];
    delete[]ucenici;
}

void Razred::EvidentirajUcenika(Ucenik *ucenik){
    if(broj_evidentiranih >= kapacitet) throw std::domain_error("Previse ucenika.\n");

    ucenici[broj_evidentiranih++] = ucenik;
}
void Razred::UnesiNovogUcenika(){
    bool pogresan_unos(1);
    while(pogresan_unos){
        Ucenik *ucenik(nullptr);
        try{
            char ime[20],prezime[20];
            int d,m,g;
            char znak1,znak2;

            std::cout<<"Ime "; std::cin >> std::setw(20)>> ime;
            std::cout<<"Prezime "; std::cin>> std::setw(20) >> prezime;
            std::cout<<"Datum rodjenja "; std::cin>> d >> znak1>>m>>znak2>>g;

         //   if(!std::cin || znak1 != "/" || znak2 != "/") std::domain_error("Pogresan datum!\n");

            // DINAMICKI ALOCIRA PEOSTOR ZA UCENIKA
            ucenik = new Ucenik(ime,prezime,d,m,g);

            for(int predmet = 1; predmet < Ucenik::DajBrojPredmeta();predmet++){
                int ocjena;
                std::cout<<"Ocjena iz "<<predmet<<" . predmeta: ";
                std::cin >> ocjena;
                 if(!std::cin) throw;

                 ucenik->PostaviOcjenu(predmet,ocjena);
            }
            //..DODAJ GA NA NIZ POKAZIVACA
            EvidentirajUcenika(ucenik);
            pogresan_unos = false;

        }catch(std::domain_error greska){
            std::cout<<greska.what()<<"\nMolimo ponovite unos:\n";

            std::cin.clear(); std::cin.ignore(10000,'\n');
            // IZBRISI ONO NA STA POKAZUJE UCENIK I STAVI POKAZIVAC NA NULU
            delete ucenik;
            ucenik = nullptr;
        }

    }
}

void Razred::IspisiIzvjestaj()const{
    std::cout<<std::endl;
    for(int i = 0; i < broj_evidentiranih;i++) ucenici[i]->Ispisi();
}

Razred::Razred(const Razred &r): kapacitet(r.kapacitet),broj_evidentiranih(r.broj_evidentiranih),ucenici(new Ucenik *[r.kapacitet]{})  {
    try{
        for(int i = 0; i < r.broj_evidentiranih;i++)
            ucenici[i] = new Ucenik( *r.ucenici[i]);
        }catch(...){
            for(int i = 0; i < broj_evidentiranih;i++)
                delete ucenici[i];
            delete[]ucenici;
        }
}

Razred::Razred(Razred &&r) : kapacitet(r.kapacitet),broj_evidentiranih(r.broj_evidentiranih),ucenici(r.ucenici){
    r.ucenici = nullptr; r.broj_evidentiranih = 0;
}
Razred &Razred::operator=(const Razred &r){
    if(kapacitet != r.kapacitet)
        throw std::domain_error("Razredi nesaglasnih kapaciteta.\n");
    if(r.broj_evidentiranih > broj_evidentiranih){
           try{
            for(int i = broj_evidentiranih; i < r.broj_evidentiranih;i++)
            ucenici[i] = new Ucenik(*r.ucenici[i]);
           }catch(...){
            for(int i = 0; i < broj_evidentiranih; i++) {delete ucenici[i]; ucenici[i] = nullptr;}
            throw;
           }
    }else{
        for(int i = broj_evidentiranih; i < r.broj_evidentiranih;i++)
           {
             delete ucenici[i]; ucenici[i] = nullptr;
           }
    }

    broj_evidentiranih = r.broj_evidentiranih;
    for(int i = 0; i < broj_evidentiranih;i++)
        *ucenici[i] = *r.ucenici[i];

    return *this;

}

Razred &Razred::operator=(Razred r){
    if(kapacitet != r.kapacitet) throw std::domain_error("Razredi u operatoru nesaglasnih kapaciteta");
    std::swap(broj_evidentiranih,r.broj_evidentiranih);
    std::swap(ucenici,r.ucenici);
    return *this;
}

Razred &Razred::operator=(Razred &&r){
    // TREBAO BI DA OBRISE SVE RESURSE ODREDISNOG OBJEKTA,UZ TEST ZA DESTRUKTIVNU SAMODODJELU,POKRADE RESURSE ,I OBJEKAT DRUGI STAVI NA NULLPTR
  if(kapacitet != r.kapacitet) throw std::domain_error("Razredi u operatoru nesaglasnih kapaciteta");
    std::swap(broj_evidentiranih,r.broj_evidentiranih);
    std::swap(ucenici,r.ucenici);
    return *this;
}
int main()
{
   try{
    int broj_ucenika;
    std::cin>>broj_ucenika;
    if(!std::cin) throw "";
    Razred razred(broj_ucenika);
    for(int i = 0; i < broj_ucenika; i++){
        std::cout<<"Unesi podatke \n";
    razred.UnesiNovogUcenika();
   }

   razred.SortirajUcenike();
   razred.IspisiIzvjestaj();

   Razred razredd(razred);
      razredd.IspisiIzvjestaj();
   }catch(...){
    std::cout<<"Memorija\n";
   }

    return 0;
}
