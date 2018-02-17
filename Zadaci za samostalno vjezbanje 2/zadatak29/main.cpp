#include <iostream>
#include <vector>

std::vector<int> funkcija(std::vector<int>v){
    std::vector<int> novi;

    for(int i = 0; i < v.size();i++){
        if(v[i] > v[i - 1] && v[i] > v[i + 1] && i > 0 && i < v.size() - 1) {
            novi.push_back(v[i]);
        }

    }

    return novi;
}

int main()
{
    std::cout<<"Unesite n: \n";
    int n;
    std::cin >> n;


    std::cout<<"Unesite elemente: \n";
    std::vector<int>v;
    for(int i = 0 ; i < n; i++){
        int br;
        std::cin >> br;
        v.push_back(br);
    }

    std::cout<<"Novi vektor: \n";
    std::vector<int>novi = funkcija(v);
    for(int i = 0; i < novi.size();i++){
        std::cout<<novi[i]<< " ";
    }
    return 0;
}
