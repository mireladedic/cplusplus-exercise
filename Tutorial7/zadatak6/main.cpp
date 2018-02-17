#include <iostream>
#include <functional>

double plus2(double x,double y){
    return x + y;
}

double plus3(std::function<double(double,double)>f ,double x,double y,double z){
    return (f(x,y) + z);
}

int main()
{
    double x,y,z;
    std::cin>> x >> y >> z;

    double rez =  plus3(plus2(x,y),x,y,z);
    std::cout<<"| "<<rez;
    return 0;
}
