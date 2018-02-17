


   /*
    void Centriraj(const Tacka &t);

    void Skaliraj(const Tacka &t,double faktor);
    void Skaliraj(double faktor);


    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);

*/

#include<iostream>
#include<cmath>

int main(){
    double pi = std::atan(1) * 4;
    double rad = pi/180.;
    std::cout<<std::sin(90 * rad)  << " " << std::cos(90 * rad)<<std::endl;
    return 0;

}
