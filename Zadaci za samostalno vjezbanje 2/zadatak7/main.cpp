#include <iostream>
int Multotpornost(int n){
   // brojac - otpornost vraca!
    int br = 1;
    int brojac = 0;

    while(br != 0){
        br = 1;
        std::cout<<n<<" | ";
        while(n != 0){
            br *= n % 10;
            n /=10;
        }
        std::cout<<br<<"\n";
        n = br;

    brojac++;
    }

   return brojac;

}

int main()
{
    std::cout<<"Unesite n: \n";
    int n;
    std::cin>>n;

    int b = Multotpornost(n);
    std::cout<<"Multiplikativna otpornost : " << b << std::endl;

    return 0;
}
