#include<iostream>
#include<vector>
#include<cmath>

bool potpunikvadrat(std::vector<int> v){
    bool jeste = false;
    for(int i = 0; i < v.size(); i++){
        if(std::sqrt(v[i]) == v[i]) jeste = true;
        }
    return jeste;
}

int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    std::vector<int>v;
    int br;
    for(int i = 0; i < n; i++){
        std::cin >> br;
        v.push_back(br);
    }

    bool potpuni = potpunikvadrat(v);
    if(potpuni) std::cout<<"Potpuni kvadrat!"<<std::endl;
    else std::cout<<"Nema potpunih kvadrata!" << std::endl;

    return 0;
}
