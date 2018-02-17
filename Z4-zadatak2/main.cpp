#include <iostream>
class GradjaninBiH{
    std::string ime_i_prezime;
  long long int  maticnibroj;
    GradjaninBiH *veza;


public:
enum Pol {Musko, Zensko};

GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol);

std::string DajImeIPrezime() const;
long long int DajJMBG() const;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const;

void PromijeniImeIPrezime(std::string novo_ime);

};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
      /*  GradjaninBiH::ime_i_prezime = ime_i_prezime;

            for(int &broj : maticnibroj)
                if(jmbg != 0){
                    broj = jmbg %10;
                    jmbg /= 10;
                }



            for(int &broj : maticnibroj)
                std::cout<<broj<<" ";

 */   GradjaninBiH *prethodni = nullptr,pocetak = nullptr;

        //...lista....
        GradjaninBiH *novi = new GradjaninBiH; // KREIRATI CE NOVOG STANOVNIKA
        novi->ime_i_prezime = ime_i_prezime;
        novi->maticnibroj = jmbg;
        novi->veza = nullptr;
        if(!pocetak ) pocetak = novi;
        else prethodni -> veza = novi;
        prethodni = novi;


    for(auto p = pocetak,p != nullptr; p->veza){
    std::cout<<p->ime_i_prezime << " " << p->maticnibroj<<std::endl;
    }
    */
}


int main()
{
    GradjaninBiH gradjani("Mirela Dedic",1402996175023);

    return 0;
}
