/* zadatak 4 */
#include <iostream>

int main()
{
    std::cout << "Unesite prirodan broj n: " << std::endl;
    int n;

/*
    std::cin >> n;
    while(!std::cin){
        std::cout<<"Unesite prirodan broj !"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
    }
    std::cout<<"broj: " << n << std::endl;
*/

    for(;;){
        std::cin >> n;
        if(std::cin) break;
        std::cout<<"Unesite prirodan broj !" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    std::cout<<"broj: " << n << std::endl;

    int br = n;
    while(std::cin){
        if(br != 0){
            std::cout<<"djelioci broja " << n << " su: ";
                int sum {0};
                for(int i = 1; i <= n ; i++){
                    if(n % i == 0){
                        std::cout << i << " ";
                        sum += i;
                    }
                }
                std::cout<<"\nsuma: " << sum <<std::endl;
        }else {
            std::cout<<"Kraj programa."<<std::endl;
        }

    break;
    }

 return 0;
}
