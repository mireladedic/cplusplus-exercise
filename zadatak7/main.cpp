#include <iostream>

class Tim{
     char ime_tima[20];
    int broj_odigranih,broj_pobjeda,broj_nerijesenih,broj_poraza,broj_datih,broj_primljenih,broj_poena;
public:
    Tim(const char ime[]);
    void ObradiUtakmicu(int broj_datih,int broj_primljenih);
    const char *DajImeTima ()const;
    int DajBrojPoena()const;
    int DajGolRazliku()const;
    void IspisiPodatke()const;
};

/*
Tim::Tim(const char ime[]): broj_odigranih(0),broj_pobjeda(0),broj_nerijesenih(0),broj_poraza(0),broj_datih(0),broj_primljenih(0),broj_poena(0){
    if(std::strlen(ime) > 20) throw std::range_error("Predugo ime.\n");
    std::strcpy(Tim::ime_tima,ime);

}

 void Tim::ObradiUtakmicu(int broj_datih,int broj_primljenih){

    if(broj_datih > broj_primljenih){
        Tim::broj_pobjeda++;
        Tim::broj_poena += 3;
    }else if(broj_datih < broj_primljenih){
        Tim::broj_poraza++;
    }else{
        Tim::broj_nerijesenih++;
        Tim::broj_poena += 1;
    }

     Tim::broj_odigranih++;
     Tim::broj_datih = broj_datih;
     Tim::broj_primljenih = broj_primljenih;
 }

    const char *Tim::DajImeTima ()const{return Tim::ime_tima;}
    int Tim::DajBrojPoena()const{ return Tim::broj_poena;}

    int Tim::DajGolRazliku()const{
        if(Tim::broj_datih < Tim::broj_primljenih){
            return (Tim::broj_primljenih - Tim::broj_datih);
        }

         return (Tim::broj_datih - Tim::broj_primljenih);

    }


    void Tim::IspisiPodatke()const{
        std::cout<<"Ime_Tima "<<ime_tima<<"\nBroj_odigranih "<<broj_odigranih<<"\nBroj_pobjeda "<<broj_pobjeda<<"\nBroj_nerijesenih "<<broj_nerijesenih<<"\nBroj_poraza "<<broj_poraza;
        std::cout<<"\nBroj_datih "<<broj_datih<<"\nBroj_primljenih "<<broj_primljenih<<"\nBroj_poena "<<broj_poena<<std::endl;
    }
    */
class Liga{
   int broj_timova;
   const int max_broj_timova;
   Tim ** timovi;

   public:
        explicit Liga(int velicina_lige): broj_timova(0),max_broj_timova(velicina_lige),timovi(new Tim*[velicina_lige]{}){}
        explicit Liga(std::initializer_list<Tim> lista_timova): broj_timova(0),max_broj_timova(lista_timova.size()),timovi(new Tim*[lista_timova.size()]{}) {}

       ~Liga(){
           for(int i = 0; i < broj_timova;i++ )delete timovi[i];
                delete[] timovi;
       }


       Liga(const Liga &l);
       Liga(Liga &&l);
       Liga &operator =(const Liga &l);
       Liga &operator =(Liga &&l);
       void DodajNoviTim(const char ime_tima[]);
       void RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2);
       void IspisiTabelu();

};
Liga::Liga(const Liga &l) {

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
