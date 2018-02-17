#include <iostream>
#include <complex>
#include <cmath>
int main()
{
    std::cout<<"Unesite broj elemenata: " << std::endl;
    int n;
    std::cin >>n;



    std::complex<double> kompleksni,clan(0,0),impedensa;
    double prividniZ, fipomak;
    for(int i = 0; i < n; i++){
        std::cin >> prividniZ;
        std::cout<<"Z_"<< i <<" = " << prividniZ<< std::endl;
        std::cin>>fipomak;
        std::cout<<"FI_"<< i <<" = " << fipomak << std::endl;

        std::cout<<"Kompleksni = " <<kompleksni << std::endl;

        clan += 1./kompleksni;
        impedensa  = 1./clan;
    }
    std::cout<<"Paralelna veza ovih elemenata ima R =  " <<impedensa.real()<< ", X = " << impedensa.imag()<<std::endl;


    return 0;
}
