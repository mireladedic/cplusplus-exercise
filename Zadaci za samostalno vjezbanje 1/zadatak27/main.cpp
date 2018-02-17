#include <iostream>
int sumc (int n){
    int br = n, sum {0};
    while(br > 0){
        int c = br % 10;
        sum += c;
        br /= 10;
    }
    return sum;
}
int main()
{
    std::cout << "Unesite a i b: " << std::endl;
    int a,b;
    std::cin >> a >> b;

    int brojac{0};
    std::cout<<"Brojevi djeljivi sumom svojih cifara su : \n";
    for(int i = a; i <= b; i++){
        if(i % sumc(i) == 0){
            std::cout<< i <<" ";
            brojac++;
        }
}
std::cout<<"brojac : " << brojac << std::endl;
    return 0;
}
