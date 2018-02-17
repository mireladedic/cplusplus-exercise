/* zadatak 3 */
#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
    std::cout << "+---------+----------+----------+" << std::endl;
    std::cout << "| Brojevi | Kvadrati | Korijeni |" <<std::endl;
    std::cout << "+---------+----------+----------+" << std::endl;

    for(int i = 1; i <= 100 ; i++){
        std::cout<< "|"<<std::setw(9)<<std::left<< i << "|" <<std::setw(10)<<std::right<< i * i << "|" << std::setw(10)<<std::right<< std::sqrt(i)<<"|"<<std::endl;
    }
    std::cout << "+---------+----------+----------+" << std::endl;
    return 0;
}
