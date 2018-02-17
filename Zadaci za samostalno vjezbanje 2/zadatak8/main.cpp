#include <iostream>
int Podbroj(int n,bool parnost){
    int br1 =0,br2 = 0;  int k = 1,k1 = 1;

    while(n != 0){
        int c = n % 10;

        if(c % 2 == 0) {br1 += c * k; k *= 10;}
        else   {br2 += c * k1; k1 *= 10;}

        n /= 10;
    }

    if(parnost) return br1;
    else return br2;

}

int main()
{
    std::cout<<"Unesite n: ";
    int n;
    std::cin>> n;


    std::cout<<"Podbroj, true = " << Podbroj(n,true) << "\nPodbroj,false = " << Podbroj(n,false);
    return 0;
}
