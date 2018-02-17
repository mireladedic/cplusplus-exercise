/* zadatak5 */
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "Unesite koeficijente kvadratne jednacine: " << std::endl;
    double a,b,c;
    std::cin >> a >> b >> c;

    while(!std::cin){
        std::cout<<"Neispravan unos!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin>> a >> b >> c;
    }

    double d = b * b - 4 * a * c;
    if(d > 0){
        double x1 =(-b + std::sqrt(d)) / (2 * a);
        double x2 =(-b - std::sqrt(d)) / (2 * a);
        std::cout<<"Rjesenja kvadratne jednacine\nx1 = " << x1 << "\nx2 = " << x2 <<std::endl;
    }else if (d == 0){
        double x1 =(-b) / (2 * a);
        double x2 = x1;
         std::cout<<"Rjesenja kvadratne jednacine\nx1 = x2 = " << x1 <<std::endl;
    }else {
        double re = (-b) / (2 * a);
        double im = std::fabs(std::sqrt(-d)/ (2 * a));
        std::cout<<"Rjesenja kvadratne jednacine\nx1 = " << re << "+" << im << "*i" << "\nx2 = " << re << "-" << im << "*i"<<std::endl;
    }
return 0;
}
