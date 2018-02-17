#include <iostream>
#include <cmath>

/*
double korjenHeronovobrazac(int number)
{
    double x = number/2; // we need some "first guess" value... N/2 should work ok...
    std::cout << "Initial approximate: " << x <<std::endl;
    for (int numRounds = 0; numRounds < 10; numRounds++)
    {
        x = (x + number/x)*0.5;
        std::cout << "next approximate: " << x << std::endl;

    }
    std::cout << "C++'s guess: " << sqrt(double(number)) << std::endl;
    return x;
}
*/
double korjenHeronovobrazac(int x){
   double a = double (x / 2);
   for(int i = 0; i <=sqrt(x);i++){
        a = (a + x/a) * 0.5;
   }
    return a;
}
int main()
{
    std::cout << "Unesite argument x: " << std::endl;
    int x;
    std::cin >> x;

    std::cout<<"Sqrt(x) = "<<sqrt(double (x))<<std::endl;
    std::cout<<"Aproksimacija Heronom = " << korjenHeronovobrazac(x)<<std::endl;

    return 0;
}
