#include <iostream>

class NeobicnaKlasa{
    int n;
public:
   explicit NeobicnaKlasa(int x) : n(x){};
   NeobicnaKlasa(const Neobicna &x):n(x){};
    void Ispisi()const{
        std::cout<<"| "<< n<<std::endl;
    }


};

int main()
{
    //NeobicnaKlasa k1(5);
    NeobicnaKlasa k2 = 5;
   // k1.Ispisi();
     k2.Ispisi();

    return 0;
}
