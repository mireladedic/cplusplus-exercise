#include <iostream>
#include <vector>
#include <cmath>
std::vector<int>funkcija(int n){
    std::vector<int>novi;

    while(n % 2 == 0){
        n /= 2;
        novi.push_back(2);
    }

    for(int i = 3; i < std::sqrt(n); i++){
        if(n % i == 0){
            novi.push_back(i);
            n/= i;
        }
       }
    if(n > 2){
        novi.push_back(n);
    }
return novi;
}

int main()
{
    std::cout<<"Unesite n: \n";
    int n;
    std::cin >> n;

    std::vector<int>v;
    v = funkcija(n);

    for(int i = 0; i < v.size();i++)
        std::cout<<v[i]<< " ";
    return 0;
}
