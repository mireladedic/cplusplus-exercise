#include <iostream>
#include <vector>

bool trocifreni(std::vector <int> v){
    bool tri = false;
    for(int i = 0; i < v.size (); i++){
        if(v[i] >= 100 && v[i] <= 999) tri = true;
    }
    return tri;
}
int main()
{
    std::vector<int> v;
    int br;
    std::cout<<"Unesite elemente: "<<std::endl;
    for(int i = 0 ; i < 3; i++){
        std::cin>> br;
        v.push_back(br);
    }

    bool troc = trocifreni(v);
    if(troc) std::cout<<"Trocifreni!"<<std::endl;
    else std::cout<<"Nije trocifreni!" << std::endl;
    return 0;
}
