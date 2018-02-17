/* zadatak 13 */
#include <iostream>
int main()
{
    std::cout << "Unesite opseg [a,b]: " << std::endl;
    int a,b;
    std::cin >> a >> b;


    for(int i = a;  i <= b; i++){
        int savrsensum {0};
            for(int j = 1; j <= i/2 ; j++){
                if(i % j == 0){
                    savrsensum += j;
                }
            }
        if(savrsensum == i) std::cout<< i << " ";
    }
    return 0;
}
