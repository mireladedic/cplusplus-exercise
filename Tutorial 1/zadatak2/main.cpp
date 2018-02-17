/* zadatak 2 */
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "Unesite tri realna broja: " << std::endl;
    double a,b,c;
    std::cin >> a >> b >> c;
    if(a > 0 || b > 0 || c > 0 || a + b > c || b + c > a || a + c > b){
        std::cout<<"Stranice cine trougao!" << std::endl;
        double pi = 4 * std::atan(1);
        double rad = 180/pi;
        double S = (a + b + c) / 2;
        double P = std::sqrt((S * (S - a)*(S - b)*(S - c)));
        double alfa = (std::acos((b * b + c * c - a * a)/ (2 * b *c))) * rad;
        double beta = (std::acos((a * a + c * c - b * b)/ (2 * a * c)))* rad;
        double gama = (std::acos((a * a + b * b - c * c) / (2 * a * b)))* rad  ;
        std::cout<<"pi :" << pi <<std::endl;
        std::cout<<"rad :" << rad <<std::endl;
        std::cout<<"S :" << S <<std::endl;
        std::cout<<"P :" << P <<std::endl;
        std::cout<<"alfa :" << alfa <<std::endl;
        std::cout<<"beta :" << beta <<std::endl;
        std::cout<<"gama :" << gama <<std::endl;

     double ugao = alfa;
     if(beta > ugao) ugao = beta;
     if(gama > ugao) ugao = gama;

     double stepeni = int(ugao);
     double minute =int ((ugao - stepeni) * 60);
     double sekunde = int((((ugao - stepeni) * 60) - minute) * 60);
     std::cout<<"Ugao ima " << stepeni << " stepeni, " << minute << " minuta, " << sekunde <<"  sekundi."<< std::endl;


    }else{
    std::cout<<"Nije trougao!"<<std::endl;
    }
    return 0;
}
