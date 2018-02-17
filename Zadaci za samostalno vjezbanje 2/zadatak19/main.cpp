#include <iostream>
#include <vector>

std::vector<int> funkcija(int n){
    std::vector<int> v;
    for(int i = 1; i < n; i++){
       if(((i - 1) & i) == 0) {
        v.push_back(i);
       }
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
