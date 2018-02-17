#include <iostream>
#include <iomanip>
int sumdjelioc(int n){
    int sum{0};
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            sum += i;
        }
    }
    return sum;
}
int main()
{
    std::cout << "Unesite n1 i n2: " << std::endl;
    int n1,n2;
    std::cin >> n1 >> n2;

    std::cout<<"+---------+---------+"<<std::endl;
    for(int i = n1; i <= n2; i++){
      std::cout<<"|"<<std::setw(9)<<std::right << i <<"|"<< std::setw(9) << std::right << sumdjelioc(i) <<"|"<< std::endl;
    }
    std::cout<<"+---------+---------+"<<std::endl;
    return 0;
}
