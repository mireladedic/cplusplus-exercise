#include <iostream>

int izbacinule(int n){
    int br = 0;
     int k = 1;
  while(n != 0){
    int c  = n % 10;

    if(c!= 0){
    br += c * k;
    std::cout<<br<<" | ";
    k*=10;
    }
    n/=10;
  }

  return br;
}

int main()
{
   std::cout<<"Unesite n: "<<std::endl;
   int n;
   std::cin>>n;

   int br = izbacinule(n);
   std::cout<<"\nBroj : " << br ;
    return 0;
}
