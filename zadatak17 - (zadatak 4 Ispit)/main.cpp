#include <iostream>
#include <vector>
#include<initializer_list>
#include <algorithm>
//REDOVNI ISPITNI ROK - > ZADATAK 4 - > GRUPA A -> GENERICKA KLASA SKUP -> ATRIBUT VEKTOR
// OPONASA OSNOVNE FUNKCIJONALNOSTI TIPA SET
// EFIKASNOST - DODAJ,IZBRISI I SEKVENCIONI KONSTRUKTOR

template<typename Tip>
class Skup{
    std::vector<Tip>elementi;
public:
    Skup() = default;
    Skup(std::initializer_list<Tip>lista);
    int Velicina()const {return elementi.size();}
    void Dodaj(const Tip &element);
    void Izbrisi(const Tip &element);
    bool ImaLiGa(const Tip &element);
    void Ispisi()const;
};

template <typename Tip>
bool Skup<Tip>::ImaLiGa(const Tip &element){
    std::binary_search(elementi.begin(),elementi.end(),element);
}

template<typename Tip>
/*
void Skup<Tip>::Dodaj(const Tip &element){
    if(ImaLiGa(element)) return;
    // SVAKI PUT NAKON UMETANJA NOVOG ELEMENTA VRSIMO SORTIRANJE -> NEEFILASNO
    elementi.push_back(element);

    std::sort(elementi.begin(),elementi.end());
}

void Skup<Tip>::Dodaj(const Tip &element){
    // PRONALAZIMO MJESTO GDJE TREBA UBACITI ELEMENT SEKVENCIONA PRETRAGA
    auto it = elementi.begin();
    while(it != elementi.end() && *it < element) it++; // PROLAZI KROZ SORTIRANI
    if(it == elementi.end() || *it != element) elementi.insert(it,element); // INSERT NEEFIKASNA ZA VEKTORE -> IZGURUJE ELEMENTE

}


void Skup<Tip>::Dodaj(const Tip &element){
    // VRSIMO BINARNU PRETRAGU
    auto it(std::lower_bound(elementi.begin(),elementi.end(),element));
    if(it == elementi.end() || *it != element) elementi.insert(it,element);
}
*/

void Skup<Tip>::Dodaj(const Tip &element){
    // POZICIJU TRAZIMO POCEV OD KRAJA UNAZAD
    auto it = elementi.end();
    while(it != elementi.begin() && *(it - 1) > element ) it--;
    if(it == elementi.begin() || *(it-1) != element) elementi.insert(it,element);
}

template<typename Tip>
/*
Skup<Tip>::Skup(std::initializer_list<Tip>lista){
    // POPUNJAVA VEKTOR U SORTIRANOM PORETKU I IZOSTAVLJA DUPLIKATE
    // BRZINA IZVRSAVANJA OVISI OD METODE DODAJ
    //std::copy(lista.begin(),lista.end(),elementi.begin());
    //DODAJE ELEMENT U VEKTOR;
    for(auto x : lista) Dodaj(x);
}

Skup<Tip>::Skup(std::initializer_list<Tip>lista){
 // IDEMO KROZ LISTU,ZA SVAKI ELEMENT PROVJERAVAMO JESMO LI GA RANIJE UBACILI,UKOLIKO NISMO STAVLJAMO GA NA KRAJ VEKTORA I SORTIRAMO
    for(auto x : lista){

        if(!ImaLiGa(x)) elementi.push_back(x); // BRZINA ZAVISI OD TOGA KOLIKO SE PUTA POZIVA METODA DODAJ
            std::sort(elementi.begin(),elementi.end());
    }
}

Skup<Tip>::Skup(std::initializer_list<Tip>lista){
    // ISKOPIRAMO ELEMENTE INICIALIZACIONE LISTE U VEKTOR, SORTIRAMO VEKTOR PA ONDA UKLANJAMO DUPLIKATE,JER SU SADA SUSJEDNI
    std::sort(elementi.begin(),elementi.end());
    auto it(elementi.begin());
    for(auto it2 = it; it2 < elementi.end(); it2++){
     if(it == elementi.begin() || *it2 != *(it2 - 1)) *it++ = *it2;
    }
    elementi.resize(it-elementi.begin());
}
*/
Skup<Tip>::Skup(std::initializer_list<Tip>lista){
    // UNIQUE UKLANJA DUPLIKATE IZ BLOKA,ALGORITHM
    std::sort(elementi.begin(),elementi.end());
    auto it = std::unique(elementi.begin(),elementi.end());
    elementi.resize(it - elementi.begin());
}
template<typename Tip>
/*
void Skup<Tip>::Izbrisi(const Tip &element){
    auto it = std::find(elementi.begin(),elementi.end(), element);
    if(it != elementi.end()) elementi.erase(it);
}


void Skup<Tip>::Izbrisi(const Tip & element){
    // BINARNA PRETRAGA
    auto it = std::lower_bound(elementi.begin(),elementi.end(),element);
    if( it != elementi.end() && *it == element) elementi.erase(it);
}
*/
void Skup<Tip>::Izbrisi(const Tip & element){
    // TRAZENJE UNAZAD
    auto it = elementi.end();
    while(--it != elementi.begin()){
        if(*it == element){
            elementi.erase(it); break;
    }
    }
}
template<typename Tip>
void Skup<Tip>::Ispisi()const{
    for(auto e : elementi) std::cout<< e << " | ";
}


int main()
{
    Skup<int>skup{1,2,3,4,5};
    skup.Ispisi();
    std::cout<<"\n";
    skup.Dodaj(8);
    skup.Ispisi();
    std::cout<<"\n";
    std::cout<<skup.Velicina();
    std::cout<<"\n";
    std::cout<<std::boolalpha<<skup.ImaLiGa(18);
     std::cout<<"\n";
     skup.Izbrisi(5);
     skup.Ispisi();
    return 0;
}
