#include <iostream>
class NeobicnaKlasa{
    int n;
public:
    explicit NeobicnaKlasa (int broj): n(broj){
        std::cout<<"Direktna inicijalizacija!\n";
    };
    NeobicnaKlasa(const double &broj): n(broj){
        std::cout<<"Kopirajuca inicijalizacija!\n";
    }
};


int main()
{
    NeobicnaKlasa k1(5);
    NeobicnaKlasa k2 = 5;

    return 0;
}
