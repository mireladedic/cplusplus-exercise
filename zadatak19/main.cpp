#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
//REDOVNI ISPITNI ROK - > ZADATAK 4 - > GRUPA C -> GENERICKA KLASA MAPA  -> VEKTOR PAROVA -> NESTO NE RADI !
template <typename Tip>

class Mapa{
   std::vector<std::pair<std::string,Tip>> parovi;
   public:
    Mapa() = default;
    Mapa(std::initializer_list<std::pair<std::string,Tip>> lista);
    int DajVelicinu()const { return parovi.size();}
    void DodajElement(const std::pair<std::string,Tip> &par);
    void IzbrisiELement(const std::string &kljuc);
    Tip NadjiElement(const std::string &kljuc);
    void IspisiMapu()const;

};
template <typename Tip>
Mapa<Tip>::Mapa(std::initializer_list<std::pair<std::string,Tip>>lista){
    for(auto x : lista){
        parovi.push_back(x);

    }
}
template <typename Tip>
void Mapa<Tip>::IspisiMapu()const{
    for(int i = 0; i < parovi.size(); i++){
        std::cout<<parovi[i].first <<"/" << parovi[i].second <<std::endl;
    }
}
template <typename Tip>
Tip Mapa<Tip>::NadjiElement(const std::string &kljuc){
   auto it =  std::find_if(parovi.begin(),parovi.end(),
                           [kljuc]( std::pair<std::string,Tip> &p){ return p.first == kljuc;}
                           );
    if(it != parovi.end()) std::cout<<"Kljuc nije pronadjen";
    return it->second;
}

template <typename Tip>
void Mapa<Tip>::DodajElement(const std::pair<std::string,Tip> &par){
    auto it = std::find_if(parovi.begin(),parovi.end(),
                           [par]( std::pair<std::string,Tip> &p){ return p.first == par.first;}
                           );

    if(it != parovi.end()) it->second = par.second;
    else{

        parovi.push_back(par);
        std::sort(parovi.begin(),parovi.end());
    }
}

template <typename Tip>
void Mapa<Tip>::IzbrisiELement(const  std::string &kljuc){
    auto it = std::find_if(parovi.begin(),parovi.end(),
                          [kljuc]( std::pair<std::string,Tip> &p) { return p.first == kljuc;}
                    );
    if(it != parovi.end())
    parovi.erase(it);
}

int main()
{
    Mapa<int> mapa{{"Mirela",2} ,{"Ajna",4}};
    mapa.IspisiMapu();
    std::cout<<"\n\n";
    mapa.DodajElement({"Irfan",3});
    mapa.IspisiMapu();
    std::cout<<"\n\n";
    mapa.IzbrisiELement(std::string ("Ajna"));
    mapa.IspisiMapu();

    return 0;
}
