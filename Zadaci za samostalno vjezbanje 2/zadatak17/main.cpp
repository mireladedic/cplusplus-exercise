#include <iostream>
#include <vector>


bool stependva (std::vector<int>v){
    bool stepen = false;
    for(int i = 0; i < v.size();i++){
        if(((v[i] - 1)& v[i]) == 0) stepen = true; // POW OF TWO BITWISE OPERATOR
    }
    return stepen;
}
int main()
{
    std::cout<<"Unesite n: \n";
    int n;
    std::cin>> n;

    std::cout<<"Unesite elemente vektora: "<<std::endl;
    std::vector<int> v;
    int br;
    for(int i = 0; i < n; i++){
        std::cin >> br;
        v.push_back(br);
    }
    if(stependva(v)) std::cout<<"Ima brojeva koji su stepen dvojke!" <<std::endl;
    else std::cout<<"Nema stepena dvojke!"<<std::endl;

    return 0;
}
/*
    2    6   5
 0010 0011 0101
 0001 0101 0100
 0000 0001 0100
 */
