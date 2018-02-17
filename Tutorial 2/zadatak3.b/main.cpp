#include <iostream>
#include <complex>
int main()
{
    std::cout<<"Unesite broj elemenata: " << std::endl;
    int n;
    std::cin >>n;



    std::complex<double> kompleksni,clan(0,0),impedensa;
    double r,x;
    for(int i = 0; i < n; i++){
        std::cin >> r;
        std::cout<<"R_"<< i <<" = " << r << std::endl;
        std::cin>>x;
        std::cout<<"X_"<< i <<" = " << x << std::endl;

        kompleksni = std::complex<double>(r,x);

        clan += 1./kompleksni;
        impedensa  = 1./clan;
    }
    std::cout<<"Paralelna veza ovih elemenata ima R =  " <<impedensa.real()<< ", X = " << impedensa.imag()<<std::endl;


    return 0;
}
