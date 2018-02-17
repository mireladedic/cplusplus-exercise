/* zadatak4 */
#include <iostream>
int main()
{
    std::cout << "Unesite podatak: " << std::endl;
    double n;
    std::cin >> n;

    for(;;){
            if(std::cin){
                 int br = n;
                 if(n > 0 && n == (int)br) std::cout<<"Podatak je prirodan broj!" <<std::endl;
                 if( n == (int)br && n < 0 ) std::cout << "Podatak je cijeli broj,ali nije prirodan!"<<std::endl;
                 if((n != (int)br) ) std::cout<<"Podatak je realan broj,ali nije cijeli!"<<std::endl;
                 break;
            }
        std::cout<<"Podatak nije broj!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
    }



    return 0;
}
