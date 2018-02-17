/* zadatak6 */
#include <iostream>
#define eps 0.00000001
int main()
{
    std::cout << "Unesite tri realna broja: " << std::endl;
    double a, b, c ;
    std::cin >> a >> b >> c;

    if( a < 0 || b < 0 || c < 0 || (a * a + b * b - c * c > eps) || (c * c - a * a - b * b > eps) || (c * c - b * b - a * a > eps) ){
        std::cout<<"Nije pravougli trougao! " << std::endl;
    }else{
        std::cout<<"Jeste pravougli trougao! " << std::endl;
    }
    return 0;
}
