#include <iostream>
#include <list>
//REDOVNI ISPITNI ROK - > ZADATAK 1 - > GRUPA D -> KRUZNA JEDNOSTRUKO POVEZANA LISTA CVOROVA ->
struct Cvor{
    long broj;
    Cvor * veza;
};

Cvor *KreirajListu(std::list<int>lista ){
    Cvor * pocetak = nullptr,*prethodni;

    for(auto x : lista){
        Cvor *novi = new Cvor;

        if(!pocetak) pocetak = novi;
        else prethodni->veza = novi;

        novi->broj = x;
        novi->veza = pocetak;
        prethodni = novi;
    }

    Cvor *p = pocetak;
    do{
        std::cout<<p->broj<<"|";
        p= p->veza;
    }while(p != pocetak);

    return pocetak;
}
int BrojParnih(Cvor * pocetak){
    //PRODJI KROZ LISTU CVOROVA
   int broj_parnih(0);

   Cvor *p = pocetak;
   do{
    if(p->broj % 2 == 0) broj_parnih++;
    p = p ->veza;
   }while(p != pocetak);

   return broj_parnih;
}

void ObrisiListu(Cvor *pocetak){
    Cvor *p = pocetak, * sljedeci;
    do{
        sljedeci = p->veza;
        delete p;
        p = sljedeci;
       // std::cout<<"0 ";
    }while(p != pocetak);
}

int main()
{
    Cvor *pocetak= KreirajListu( {1,2,3,4,5,6,7,8,9,10});
    int broj_parnih = BrojParnih(pocetak);

   std::cout<<"\nbroj_parnih " << broj_parnih<<std::endl;

   ObrisiListu(pocetak);




    return 0;
}
