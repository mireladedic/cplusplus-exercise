#include <iostream>
#include <stdexcept>

class StedniRacun{
   double stanje_racuna;
    int *broj_aktivnih;
    int *broj_kreiranih;
public:

    StedniRacun(double pocetna_vrijednost=0) : stanje_racuna(pocetna_vrijednost),broj_aktivnih(new int (0)),broj_kreiranih(new int(0)) {
        if(pocetna_vrijednost < 0) throw std::domain_error("Nedozvoljena pocetna vrijednost!\n");
        (*broj_kreiranih)++;
        (*broj_aktivnih)++;
    }

    void Ulozi(double iznos) {
        if(iznos > stanje_racuna) std::domain_error("Iznos veci od stanja racuna!\n");
        stanje_racuna += iznos;
        }
    void Podigni(double iznos){
         if(iznos > stanje_racuna) std::domain_error("Iznos veci od stanja racuna!\n");
         stanje_racuna -= iznos;
    }
    double DajStanje() const{ return stanje_racuna; }

    void ObracunajKamatu(double procenat_kamate) {

        if(procenat_kamate < 0) throw std::domain_error("Kamantna stopa negativna.\n");
        stanje_racuna = stanje_racuna + ((stanje_racuna * procenat_kamate) / 100);
    }

    int DajBrojKreiranih()const { return *broj_kreiranih; }
   int DajBrojAktivnih()const{return *broj_aktivnih; }

    ~StedniRacun(){
        if((*broj_aktivnih ) == 0 ) delete broj_aktivnih;
        else {broj_aktivnih--; }

        if((*broj_kreiranih) == 0) delete broj_kreiranih;
    }

};

int main()
{
    StedniRacun stedni(100);
    stedni.Ulozi(50);
    std::cout<<"| "<< stedni.DajStanje();
    stedni.Podigni(100);
    std::cout<<"| "<< stedni.DajStanje();
    stedni.ObracunajKamatu(12.5);
    std::cout<<"| "<< stedni.DajStanje();

     StedniRacun s1, s2(100);
       // { StedniRacun s3(50); }
        std::cout<<StedniRacun::DajBrojKreiranih() << " " << StedniRacun::DajBrojAktivnih();
        return 0;
}

