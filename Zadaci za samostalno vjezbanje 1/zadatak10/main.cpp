/* zadatak10 */
#include <iostream>
int main()
{
    std::cout << "Unesite x i n: " << std::endl;
    double x; int n;
    std::cin >> x >> n;
    double sum {0};
    int step = 1;
    for(int k = 1; k <= n; k++){
        step *= (-1);
        sum += step / (x * (x + k)) ;
    }
    std::cout<<"sum = " << sum <<std::endl;
    return 0;
}
