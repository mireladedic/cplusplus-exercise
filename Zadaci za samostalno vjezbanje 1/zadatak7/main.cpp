/* zadatak7 */
#include <iostream>
#include <iomanip>
int main()
{
    std::cout << "Unesite glavnicu i kamatnu stopu: " << std::endl;
    int G,p;
    std::cin >> G >> p;

    double K = (double)G * p / 100;
    double S = (double)G + K;

//zaokruzivanje broja
    if( K - (int)K < 0.5 ){ K = (int)K; }
    else { K = (int)K + 1; }

    if( S - (int)S < 0.5 ){ S = (int)S; }
    else { S = (int)S + 1; }

    std::cout<< std::setw(15) << std::left <<"Glavnica: "      << std::setw(6) << std::right << G << std::endl;
    std::cout<< std::setw(15) << std::left <<"Kamatna stopa: " << std::setw(6) << std::right << p << std::endl;
    std::cout<< std::setw(15) << std::left <<"Kamate: "        << std::setw(6) << std::right << K << std::endl;
    std::cout<< std::setw(15) << std::left <<"Nova svota: "    << std::setw(6) <<std::right << S << std::endl;

    return 0;
}
