#include <iostream>
#include <list>
#include<complex>
// REDOVNI ISPITNI ROK - > ZADATAK 1 - > GRUPA A -> JEDNOSTRUKO POVEZANA LISTA CVOROVA
struct Kompleksni{
    double re,im;
    Kompleksni *sljedeci;
};

Kompleksni *KreirajListu(std::list<std::complex<double>> lista){
Kompleksni *pocetak = nullptr,*prethodni;

   for(auto z : lista){


    Kompleksni *novi = new Kompleksni;
    novi->re = z.real(); novi->im = z.imag(); novi->sljedeci = nullptr;


    if(!pocetak) pocetak = novi;
    else prethodni->sljedeci = novi;

    prethodni = novi;
   }

 for(Kompleksni *pokazivac = pocetak; pokazivac != nullptr ; pokazivac = pokazivac->sljedeci){
    std::cout<<"( "<<pokazivac->re<<" , "<<pokazivac->im<<" )"<<std::endl;
 }

 return pocetak;
}

int main()
{
    std::list<std::complex<double>>lista{{1,2}, {3,4}, {5,6}};
    Kompleksni *z = KreirajListu(lista);


    // PRETPOSTAVKA DA IMA ObrisiListu() FUNKCIJA U PROGRAMU
    ObrisiListu(z);
    return 0;
}
