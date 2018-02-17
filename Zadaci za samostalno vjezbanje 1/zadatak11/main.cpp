
#include <iostream>
#include <cmath>
/*
double factorial(int k){
    double fact = 1;
    if(k == 0) fact = 1;
    for(int i  = 1 ; i <= k; i++){
        fact *= i;
    }
    return fact;
}

double power (double baza, int stepen) {
   double step = 1;
   if(stepen > 0){
    for(int i = 0; i < stepen;i++)
        step *= baza;
   }else if(stepen == 0){
        step = 1;
   }else{
    for(int i = 0; i > stepen; i--)
        step /= baza;
   }
   return step;
}
*/
int main()
{
    std::cout<<"Unesite x : " << std::endl;
    double x;
    std::cin >> x;

    double S = 0, F ;
    int k = 0;
    do{
        //.... e ^ x
        F = std::exp(x);
        // ..... FAKTORIJEL
        double fact = 1;
        if(k == 0) fact = 1;
        else
        for(int i  = 1 ; i <= k; i++){
            fact *= i;
        }
        //..... STEPEN
        double step = 1;
        if(k == 0){
        step = 1;
        }else if(k  > 0){
        for(int i = 0; i < k;i++)
        step *= x ;
        }else{
        for(int i = 0; i > k; i--)
        step /= x;
        }
        //... APROKSIMACIJA TAJLOROVIM POLINOMOM
        S += step / fact;

        k++;
    }while(std::fabs(S - F) > 0.00001);

  std::cout<<"n = " << k << std::endl;
  std::cout<<"S = " << S << std::endl;
  std::cout<<"F = " << F << std::endl;

  return 0;
}
