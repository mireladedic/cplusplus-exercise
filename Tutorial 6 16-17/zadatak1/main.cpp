#include <iostream>
#include <stdexcept>

template<typename Tip>
Tip *GenerirajStepeneDvojke(int n){
    if(n < 0) throw std::domain_error("Broj elemenata mora biti pozitivan!\n");
    Tip *niz = nullptr;
    if(sizeof(Tip) < n) throw std::overflow_error("Prekoracen dozvoljen opseg!\n");
    try{

    Tip *niz = new Tip [n];
        int step = 1;
        for(int i (0); i < n; i++){
                niz[i] = step;
                step *= 2;
            std::cout<<"| "<<niz[i];


        }
           return niz;
    }catch(std::runtime_error){
        delete[] niz;
            std::cout<<"Alokacija nije uspjela!\n";
    }

}
int main()
{

    std::cout << "Koliko zelite elemenata: " << std::endl;
    int n;
    std::cin>> n;

    long long int *pok = GenerirajStepeneDvojke<long long int>(n);
    std::cout<<"\npoziv funkcije:\n";
    for(int i = 0; i < n; i++){
        std::cout<<pok[i]<<" ";
    }
    return 0;
}
