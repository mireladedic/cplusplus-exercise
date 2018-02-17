/* zadatak 12 */
#include <iostream>
#include <cmath>
int main()
{
    std::cout<<"Unesite brojeve: " <<std::endl;
    double n;
    int br {0} ;
    double aritmetic {0} , geometric {1};

    while(n != 0){
        std::cin >> n;
        if(n != 0){
            br++;
            aritmetic += n;
            geometric *= n;
        }
    }
    double resultaritm =  aritmetic / (double)br ;
    double resultgeom = std::pow(geometric, (1./br));

    std::cout<<"Aritmeticka sredina =  " << resultaritm << std::endl;
    std::cout<<"Geometrijska sredina = " << resultgeom  << std::endl;
    return 0;
}
