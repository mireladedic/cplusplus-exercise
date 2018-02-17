#include <iostream>
#include <deque>
#include <utility>
#include <string>
#include <algorithm>
#include <initializer_list>
//REDOVNI ISPITNI ROK - > ZADATAK 4 - > GRUPA d -> GENERICKA KLASA MAPA  ->
template<typename Tip>
class Mapa{
    std::deque<std::pair<std::string,Tip>> parovi;
public:
    Mapa() = default;
    Mapa(std::initializer_list<std::pair<std::string,Tip>> lista);
    int Velicina()const { return parovi.size(); }
    void Dodaj(const std::pair<std::string,Tip> &par);
    void Izbrisi(const std::string &kljuc);
    Tip Nadji(const std::string &kljuc);
    void Ispisi()const;
};
template<typename Tip>
Mapa<Tip>::Mapa(std::initializer_list<std::pair<std::string,Tip>> lista){
    for(auto x : lista){
        parovi.push_back(x);
    }

    std::sort(parovi.begin(),parovi.end());
}
template<typename Tip>
void Mapa<Tip>::Dodaj(const std::pair<std::string,Tip> &par){
    // AKO IM JE ISTI KLJUC MIJENJA SE VRIJEDNOST
    auto it = std::find_if(parovi.begin(),parovi.end(),
                           [par](const std::pair<std::string,Tip> &p){ return p.first == par.first;}
                           );
    if(it != parovi.end()) it->second = par.second;
    // DODAJ NOVI NOVCATI PAR
    parovi.push_back(par);
    std::sort(parovi.begin(),parovi.end());

}

template<typename Tip>
 void Mapa<Tip>::Izbrisi(const std::string &kljuc){
    auto it = std::find_if(parovi.begin(),parovi.end(),
                           [kljuc](const std::pair<std::string,Tip> &p){return p.first == kljuc;}
                           );
    if(it != parovi.end())   parovi.erase(it);
 }

template<typename Tip>
Tip Mapa<Tip>::Nadji(const std::string &kljuc){
   auto it = std::find_if(parovi.begin(),parovi.end(),
                 [kljuc](const std::pair<std::string,Tip> &p) {return p.first = kljuc;}
                 );
    if(it == parovi.end()) std::cout<<"Kljuc nije pronadjen";
    return it->second;
}
template<typename Tip>
void Mapa<Tip>::Ispisi()const{
    for(int i = 0; i < parovi.size();i++)
        std::cout<<parovi[i].first <<"/" << parovi[i].second<<std::endl;
}
int main()
{
    Mapa<int>mapa{ {"Mirela",1} , {"Ajna", 2}};
    mapa.Ispisi();
    std::cout<<"\n\n";
    mapa.Dodaj({"Irfan",3});
    mapa.Ispisi();
    std::cout<<"\n\n";
    mapa.Izbrisi("Ajna");
    mapa.Ispisi();
    return 0;
}
