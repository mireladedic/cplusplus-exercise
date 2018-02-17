#include <iostream>

int main()
{
    std::cout << "Unesite n: " <<std::endl;
    int n;
    std::cin >> n;

    double cln ,sum {0};
    for(int i = n ; i >= 1 ; i--){
        cln = 1./n;
        sum += 1. / ( i + cln);

    }
    std::cout<<"cln = " << cln << std::endl;
    std::cout<<"sum = " << sum << std::endl;
    return 0;
}
