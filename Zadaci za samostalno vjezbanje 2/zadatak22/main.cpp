#include <iostream>
#include <vector>

std::vector<int> funkcija(int niz[], int vel){
    int brojac{0};
    std::vector<int> vek;
    for(int i = 0; i < vel; i++){
        if(niz[i] % 2 == 0)
        {
            brojac++;
            vek.push_back(niz[i]);

        }

    }

    for(int i = 0; i <vel; i++){
        if(niz[i] % 2 != 0) vek.push_back(niz[i]);
    }

    return vek;

}


int main()
{
    std::cout<<"Unesite velicinu: " << std::endl;
    int vel;
    std::cin >> vel;

    int niz[vel];
    std::cout<<"Unesite elemente niza: "<< std::endl;
    for(int i = 0; i < vel; i++){
        int br;
        std::cin >>br;
        niz[i] = br;
    }

    std::vector<int> vektor;
    vektor = funkcija(niz,vel);

    std::cout<<"Elementi vektora: " << std::endl;
    for(int i = 0; i < vektor.size(); i++){
        std::cout<<vektor[i] << " ";
    }
    return 0;
}
