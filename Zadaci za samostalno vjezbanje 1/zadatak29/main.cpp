#include <iostream>

double stepen(int x,int n = 2){
    double step = 1.0;
    if(n == 0) step = 1;
    else if(n > 0){
        for(int i = 1; i <= n; i++)
            step *= x;
    }else if(n < 0){
        for(int i = n; i < 0; i++)
            step /= x;
    }
    return step;
}
int main()
{
    /*
    std::cout <<stepen(2,5)<< std::endl;
    std::cout<<stepen(10,-3)<<std::endl;
    std::cout<<stepen(4)<<std::endl;
    */

    std::cout<<"Unesite bazu i eksponent: "<<std::endl;
    int x,n;
    std::cin >> x >> n;

    std::cout <<"x ^ n = "<<stepen(x,n)<< std::endl;

    return 0;
}
