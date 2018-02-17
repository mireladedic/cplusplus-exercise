#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> funkcija(int n){
    std::vector<int>v;
          //int k = 0;
          for(int i = 1; i < std::sqrt(n);i++){
           int k = i*i;
            std::cout << i << " | " << i*i<< std::endl;
            v.push_back(k);
            //std::cout << k << std::endl;
            //k++;
          }
return v;
}
int main()
{
     std::cout << "Unesite n: " << std::endl;
    int n;
    std::cin>> n;

    std::vector<int> v;
    v = funkcija(n);

    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<" ";
    }

    return 0;
}
