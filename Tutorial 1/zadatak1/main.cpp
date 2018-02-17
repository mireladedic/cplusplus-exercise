#include <iostream>
int main()
{
    std::cout << "Unesite dimenzije (axbxc) u metrima: " << std::endl;
    int x,y,z;
    std::cin >> x >> y >> z;

    std::cout<< "Unesite dimenzije plocice (axb) u centrimetrima: "<< std::endl;
    int a,b;
    std::cin  >> a >> b;

    int ukupno;
    ukupno = (((x * y )+ (2 * y * z) + (2 * x * z)) * (a * b * 0.01)) * 100;
    std::cout << "Za poplocavanje bazena dimenzija (" << x << " x " << y << " x " << z <<")"<<std::endl;
    std::cout << "plocicama dimenzija (" << a << " x " << b << ") potrebno je " << ukupno << " plocica"<<std::endl;
    return 0;
}
