#include <iostream>
#include <complex>
int main()
{
    std::cout<<"Unesite broj elemenata: " << std::endl;
    int n;
    std::cin >>n;



    std::complex<double> kompleksni,impedensa,clan = (0,0);
    double r,x;
    for(int i = 0; i < n; i++){
        std::cin >> r >> x;
        kompleksni = std::complex<double>(r,x);
        std::cout<<"Z_"<< i <<" = " << kompleksni << std::endl;
        clan += 1./kompleksni;
        impedensa  = 1./clan;
    }
    std::cout<<"impedensa = " <<impedensa<<std::endl;


    return 0;
}
