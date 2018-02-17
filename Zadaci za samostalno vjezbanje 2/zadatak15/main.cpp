#include <iostream>
#include<vector>
std::vector<int> funkcija (int niz[], int vel){
    std::vector<int> v;

    for(int i = vel - 1; i >= 0 ; i--){
        v.push_back(niz[i]);
    }

    return v;
}

int main()
{
    std::cout<<"Unesite elemente niza: "<<std::endl;
    int vel = 5;
    int niz[vel];

    int broj;

    for(int i = 0; i < vel; i++){
        std::cin>> broj;
        niz[i] = broj;
    }

    std::vector<int>vraceni = funkcija(niz, vel);

    std::cout<<"Elementi vektora: " << std::endl;
    for(int i = 0; i < vraceni.size(); i++){
        std::cout<< vraceni[i] << " ";
    }

    return 0;
}
