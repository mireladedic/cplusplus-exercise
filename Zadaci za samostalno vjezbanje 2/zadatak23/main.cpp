#include <iostream>
#include <vector>

std::vector<int>funkcija(std::vector<int> v){
    std::vector<int> vek;

    for(int i = 0; i < v.size();i++){
        int br{0}; // ... BROJAC UNUTAR PETLJE DA POSLIJE SVAKOG BROJA RESTARTUJE
        int n = v[i];
        while(n != 0){
            int c = n % 10;
            br++; std::cout<<br<<" | ";
            n/= 10;

        }
        vek.push_back(br);

    }

    return vek;
}

int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    std::cout<<"Unesite elemente: "<<std::endl;
    std::vector<int>brojevi;
    for(int i = 0; i < n; i++){
        int br;
        std::cin>>br;
        brojevi.push_back(br);
    }

    std::vector<int>v =  funkcija(brojevi);
    std::cout<<"Elementi vektora: "<<std::endl;
    for(int i = 0; i < v.size();i++){
        std::cout<<v[i]<<" ";
    }
    return 0;
}
