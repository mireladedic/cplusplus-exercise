/* zadatak2 */
#include <iostream>
#define milja 1852
int main()
{
    std::cout << "Unesite brzinu broda u cvorovima: " << std::endl;
    int brzinacvor;
    std::cin >> brzinacvor;

    double pretvorba = (double) milja/1000;
    std::cout<<"p : " <<pretvorba<<std::endl;

    double brzinakilometar = (double) brzinacvor * pretvorba;
    std::cout<<"Brzina broda: " << brzinakilometar << std::endl;
    return 0;
}
