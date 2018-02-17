#include <iostream>
#include <list>
#include <vector>
#include<utility>
// REDOVNI ISPITNI ROK - > ZADATAK 1 - > GRUPA B -> CIRKULARNA KRUZNA JEDNOSTRUKO POVEZANA LISTA CVOROVA
struct Koordinate{
    double x,y;
    Koordinate *sljedeci;
};
Koordinate *KreirajListu(std::vector<std::pair<double,double>> lista){
Koordinate *pocetak = nullptr,*prethodni;

    for(auto koord : lista){
        Koordinate *novi = new Koordinate;
        if(!pocetak) pocetak = novi;
        else  prethodni->sljedeci = novi;

        novi->x = koord.first;
        novi->y = koord.second;
        novi->sljedeci = pocetak;

        prethodni = novi;

    }
    Koordinate *p = pocetak;
    do{
        std::cout<<p->x << " | "<< p->y<<std::endl;
        p = p->sljedeci;
    }while(p != pocetak);

    return pocetak;
}


int main()
{
    std::vector<std::pair<double,double>> lista_parova{ {1,2}, {3,4}};
    Koordinate *pocetak = KreirajListu(lista_parova);
    //ObrisiLISTU(pocetak);
    return 0;
}
