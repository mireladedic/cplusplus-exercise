#include <iostream>
#include <vector>
bool parni (std::vector<int> v){
    bool parnibroj = false;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 == 0)
         parnibroj = true;
         }
    return parnibroj;
}

int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    int br;
    std::vector<int>v;
    for(int i = 0; i < n ; i++){
        std::cin>>br;
        v.push_back(br);
    }

    bool par = parni(v);
    if(par) std::cout<<"Postoje parni brojevi!\n";
    else std::cout<<"Svi neparni!\n";
    return 0;
}
