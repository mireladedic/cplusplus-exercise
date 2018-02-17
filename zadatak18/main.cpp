#include <iostream>
#include <deque>
#include <algorithm>
#include <initializer_list>
//REDOVNI ISPITNI ROK - > ZADATAK 4 - > GRUPA B -> GENERICKA KLASA SKUP -> DEK
template<typename Tip>

class Skup{
    std::deque<Tip>elementi;
public:
    Skup() = default;
    Skup(std::initializer_list<Tip>lista);
    int DajVelicinu()const {return elementi.size();}
    void DodajElement(const Tip &element);
    void IzbrisiElement(const Tip &element);
    bool ImaLiElementa(const Tip &element);
    void Ispisi()const;
};

template<typename Tip>
Skup<Tip>::Skup(std::initializer_list<Tip>lista){
    for(auto x : lista) DodajElement(x);
}

template<typename Tip>
void Skup<Tip>::DodajElement(const Tip &element){
    if(ImaLiElementa(element)) return;
    elementi.push_back(element);
    std::sort(elementi.begin(),elementi.end());
}

template<typename Tip>
void Skup<Tip>::IzbrisiElement(const Tip &element){
    if(!ImaLiElementa(element)) return;
    auto it = std::find(elementi.begin(),elementi.end(),element);
  //  while(it != elementi.end() && *it < element) it++;
    if(it != elementi.end()) elementi.erase(it);
}

template<typename Tip>
bool Skup<Tip>::ImaLiElementa(const Tip & element){
    std::binary_search(elementi.begin(),elementi.end(),element);
}

template<typename Tip>
void Skup<Tip>::Ispisi() const{
    for(int i = 0; i < elementi.size(); i++){
        std::cout<<elementi[i]<<"| ";
    }
    std::cout<<std::endl;
}
int main()
{
    Skup<int> skup{1,2,3,4,5};
    skup.Ispisi();
    skup.DodajElement(6);
    skup.Ispisi();
    skup.IzbrisiElement(5);
    skup.Ispisi();
    std::cout<<std::boolalpha<<skup.ImaLiElementa(8)<<std::endl;
    std::cout<<skup.DajVelicinu();
    return 0;
}
