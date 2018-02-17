#include <iostream>

void zbircifara(int n,int &vece,int &manje){
    int pet_vece (0),pet_manje (0);
    while(n != 0){
        if((n % 10) % 2 > 5) pet_vece += n % 10;
        else pet_manje +=  n % 10;
    }
    vece = pet_vece;
    manje = pet_manje;
}
int main()
{
   std::cout<<"Unesite broj:\n";
   int broj;
   std::cin >> broj;

int    vece,manje;

   zbircifara(broj,vece = 0, manje= 0);

   std::cout<<vece<<" | "<<manje;
    return 0;
}
