#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
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
int main()
{

    Tim tim("Zeljeznicar");
    tim.ObradiUtakmicu(3,2);
    tim.IspisiPodatke();
    return 0;
}
