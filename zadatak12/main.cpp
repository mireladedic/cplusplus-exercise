#include <iostream>
#include <memory>
struct Cvor{
    int element;
   // Cvor *veza;
   //std::shared_ptr<Cvor>veza;

   std::shared_ptr<Cvor>prethodni,sljedeci;
};

int main()
{

    std::shared_ptr<Cvor>c1 (new Cvor);
    std::shared_ptr<Cvor>c2 (new Cvor);
    c1->veza = c2; c2->veza = c1;

    std::shared_ptr<Cvor>c1;
    std::shared_ptr<Cvor>c2;
    c1->prethodni = nullptr;
    c1->sljedeci = c2;
    c2->prethodni = c1;
    c2->sljedeci = nullptr;
    /*...JEDNOSTRUKO POVEZANA LISTA -> CVOROVI -> NODES
    std::cout<<"Unesite elemente cvora: \n";
    Cvor *pocetak = nullptr, *prethodni;
    for(;;){

    int x;
    std::cin >> x;
    if(x == 0) break;

    Cvor *novi = new Cvor;
    novi->element = x;
    novi->veza = nullptr;

    if(!pocetak) pocetak = novi;
    else prethodni->veza = novi;

    prethodni = novi;
    }
    std::cout<<"ispis:\n";

    std::cout<<pocetak->element<< std::endl; // PRVI CVOR
    std::cout<<pocetak->veza->element<<std::endl; // DRUGI CVOR
    std::cout<<pocetak->veza->veza->element<<std::endl; // TRECI CVOR

    // ISPISI CVOR
    for(Cvor *pokazivac = pocetak; pokazivac != nullptr; pokazivac = pokazivac->veza){
        std::cout<<pokazivac->element<<"|";
    }
*/
    return 0;
}
