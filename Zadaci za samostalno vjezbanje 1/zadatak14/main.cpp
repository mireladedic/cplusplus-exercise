/* zadatak 14 */
#include <iostream>
int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    int br = n; int palindrom {0};
    while(br > 0){

        int c = br % 10;
        palindrom = (palindrom * 10) + c;
        br /= 10;
    }
    std::cout<<"Palindrom = "<<palindrom<<std::endl;
    if(palindrom == n) std::cout<<"Jeste\n";
    else {std::cout<<"Nije\n"; }
    return 0;
}
