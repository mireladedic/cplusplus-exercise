#include <iostream>
#include<list>
//REDOVNI ISPITNI ROK - > ZADATAK 1 - > GRUPA C ->  JEDNOSTRUKO POVEZANA LISTA CVOROVA -> BUG
struct Cvor{
    unsigned int broj;
    Cvor *veza;

};
Cvor *KreirajListu(std::list<int>lista){
    Cvor *pocetak = nullptr,*prethodni;
    for(auto l : lista){

       Cvor *novi = new Cvor;
       novi->broj = l;
       novi->veza = nullptr;

       if(!pocetak) pocetak = novi;
       else prethodni->veza = novi;

       prethodni = novi;
    }
    std::cout<<"Kreirana lista:\n";
    for(Cvor * p = pocetak; p != nullptr;p= p->veza)
        std::cout<<p->broj<<"|";
    return pocetak;
}
int BrojProstih(Cvor *pocetak){

    unsigned int broj_prostih(0);

    for(Cvor *p = pocetak; pocetak != nullptr; p = p->veza){

        unsigned int broj_djelilaca(0);
        // AKO JE DJELJIV SA 1 I SA SAMIM SOBOM, TO ZNACI DA JE BROJ DJELILACA JEDNAKO 2
        for(unsigned int i = 1; i <= p->broj;i++)
            if(p->broj % i == 0) broj_djelilaca++;

        if(broj_djelilaca == 2) broj_prostih++;

    }

        return broj_prostih;
}

void ObrisiListu(Cvor *pocetak){
    Cvor *sljedeci;
    for(Cvor *p = pocetak; p != nullptr;p= sljedeci)
    {
       sljedeci = p->veza;
       delete p;
    }
}

int main()
{
    Cvor *pocetak = (KreirajListu({3,7,8,10,6,2,4,9}));
   unsigned int broj = BrojProstih(pocetak);
    std::cout<<"| "<<broj;

    ObrisiListu(pocetak);
    return 0;
}
