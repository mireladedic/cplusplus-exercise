#include <iostream>
#include <cmath>
int main()
{
   std::cout<<"Unesite x: "<<std::endl;
   double x;
   std::cin >> x;

   std::cout<<"Unesite n - najveci stepen polinoma: "<< std::endl;
   int n;
   std::cin >> n;

   std::cout<<"Unesite koeficijente: " <<std::endl;
   double polinom = 0;
    for(int i = n; i > 0 ; i--){
        int A;
        std::cin >> A;

        polinom += A * pow(x,n);

    }
    std::cout<<"P(X) = " << polinom << std::endl;

    return 0;
}
