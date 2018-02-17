#include <iostream>
#include <vector>



std::vector<int> funk(int n){
    std::vector<int> v;
    for(int i = 100; i < 999; i++){

        if(i % n == 0)
            v.push_back(i);
        }

    return v;
}

int main()
{
    std::cout<<"Unesite n: " << std::endl;
    int n;
    std::cin >> n;

        std::vector<int> vek = funk(n);


        for(int i = 0; i < vek.size(); i++){
            std::cout<<vek[i] <<" ";
        }
    return 0;
}
