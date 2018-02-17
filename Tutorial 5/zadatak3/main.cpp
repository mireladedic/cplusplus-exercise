#include <iostream>
#include <algorithm>

int main()
{
    std::cout<<"Unesite n: \n";
    int n;
    std::cin >> n;

    int niz[n];
    for(int i = 0; i < n; i++){
        std::cin >> niz[i];
    }


    std::cout<<std::max_element(niz.begin(),niz.end());
    return 0;
}
