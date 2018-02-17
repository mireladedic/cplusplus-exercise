#include <iostream>

int main()
{
    std::cout << "Unesite n: " << std::endl;
    int n;
    std::cin >> n;

    double sum {0},rez {0};
    std::cout<<"Unesite " << n << " clana sume: " <<std::endl;
    for(int i = 0; i < n; i++)
    {
       double  br;
       std::cin >> br;
       sum += br;
       rez += 1/sum;

    }
    std::cout << "(1 / a1 + a/ a1 + a2 + 1/ a1 + a2 + ...) = " << rez <<std::endl;

    return 0;
}
