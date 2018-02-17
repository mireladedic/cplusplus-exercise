#include <iostream>
#include <string>
#include <vector>



int main()
{
    std::cout<<"Unesite recenicu: \n";
    char recenica[50];
    std::cin.getline(recenica,sizeof(recenica));

    std::cout<<"Unesite spisak rijeci: \n";
    std::vector<std::string>spisak;
    for(int i = 0; i < spisak.size(); i++){
        char rijec[50];
        spisak.push_back( std::cin.getline(rijec,sizeof(rijec)));

    }
}
