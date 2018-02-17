#include <iostream>
#include<stdexcept>
#include <cmath>

// APSTRAKTNA KLASA LIK
class Lik{
public:
    virtual    void IspisiSpecificnosti() const = 0;
    virtual double DajObim () const = 0;
    virtual  double DajPovrsinu () const = 0;

    void Ispisi() const {
        IspisiSpecificnosti();
        std::cout<<"O = " << DajObim() << " | P = " << DajPovrsinu() << std::endl;
    }
};


class Krug : public Lik{
    double r;
    static constexpr double PI = 3.14;
public:
    Krug(double r) : r(r){
        if(r <= 0) throw std::domain_error("Neispravan parametar - krug");
    }

    void IspisiSpecificnosti() const override;
    double DajObim () const override;
    double DajPovrsinu () const override;
};


void Krug::IspisiSpecificnosti() const {
    std::cout<<"Krug poluprecnika " << r << std::endl;
}
double Krug::DajObim () const{
    return 2 * PI * r;
}
double Krug::DajPovrsinu() const{
    return r * r * PI;
}

class Pravougaonik : public Lik{
    double a,b;
public:
    Pravougaonik (double a,double b) : a(a) , b(b){
        if(a <= 0 || b <= 0 ) throw std::domain_error("Neispravni parametri - pravougaonik");
    }
    void IspisiSpecificnosti() const override;
    double DajObim () const override;
    double DajPovrsinu () const override;
};

void Pravougaonik::IspisiSpecificnosti() const{
    std::cout<<"Pravougaonik sa stranicama duzine " << a << "  i " << b << std::endl;
}
double Pravougaonik::DajObim () const{
    return 2 * (a + b);
}
double Pravougaonik::DajPovrsinu () const {
    return a * b;
}




class Trougao : public Lik{
    double a,b,c;
public:
    Trougao(double a , double b, double c) : a(a) , b(b) , c(c){
        if(a <= 0 || b <= 0 || c <= 0) throw std::domain_error("Neispravni parametri - trougao");
    }
    void IspisiSpecificnosti() const override;
    double DajObim () const override;
    double DajPovrsinu () const override;
};


void Trougao::IspisiSpecificnosti() const {
    std::cout<<"Trougao sa stranicama duzine " << a << " , " << b << " , " << c << std::endl;
}
double Trougao::DajObim () const{
    return a + b + c;
}
double Trougao::DajPovrsinu () const {
    double s = Trougao::DajObim() / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
int main()
{
   Krug k (7.8);
   k.Ispisi();
   Pravougaonik p(1,8);
   p.Ispisi();
   Trougao t (1.3,2.5,3.6);
   t.Ispisi();

    return 0;
}
