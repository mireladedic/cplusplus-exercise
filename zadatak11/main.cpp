#include <iostream>
#include <map>
#include <string>
#include<utility>
#include<array>
template<typename Tip,int broj_elemenata>
struct Umotaniniz{
    Tip elementi[broj_elemenata];
};
template<typename Tip,int broj_elemenata>
void IspisiUmotaniniz(Umotaniniz<Tip,broj_elemenata> niz){
    for(int i = 0; i < broj_elemenata;i++)
        std::cout<<niz.elementi[i]<<"|";
}
int main()
{

    std::array<double,5> a;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
   for(auto it = a.begin(); it != a.end();it++){
    std::cout<<*it<<"|";
   }
  // a.data() - > kada se salje funkciji koja prima klasicni niz
    /*
    Umotaniniz<int,3>niz;
    niz.elementi[0] = 1; niz.elementi[1] = 2;
    niz.elementi[2] = 3;
    IspisiUmotaniniz(niz);


    std::map<std::string,int>stanovnistvo{ {"Sarajevo",4500}, {"Banja Luka",200} , {"Mostar",850} };
    stanovnistvo.insert(std::make_pair(std::string("Sarajevo"),4500));
    stanovnistvo.insert(std::make_pair(std::string("Banja Luka"),200));
    stanovnistvo.insert(std::make_pair( std::string("Mostar"),850));
    `

    for(auto it = stanovnistvo.begin(); it != stanovnistvo.end();it++){
        std::cout<<"GRAD "<< it->first <<"\n"<< "BROJ STANOVNIKA " << it -> second<<"\n";
    }

    //PRONADJI MOSTAR I ISPISI
    auto it = stanovnistvo.find("Mostar");
    if(it == stanovnistvo.end()) std::cout<<"Nema podataka!\n";
    else std::cout<<"GRAD "<<it->first <<" BROJ STANOVNIKA " <<it->second;


    std::cout<<" BROJ STANOVNIKA "<<stanovnistvo["Sarajevo"];

    std::cout<<" BROJ STANOVNIKA "<<stanovnistvo["Gorazde"];

    std::cout<<std::endl;

     for(auto it = stanovnistvo.begin(); it != stanovnistvo.end();it++){
        std::cout<<"GRAD "<< it->first <<"\n"<< "BROJ STANOVNIKA " << it -> second<<"\n";
    }

    if(!stanovnistvo.count("Neum")) std::cout<<"Nema podataka!\n";
    else std::cout<<stanovnistvo["Neum"];
    */

    //... ARRAY


    return 0;
}
