#include <iostream>

int main()
{
    std::cout << "Unesite n : "<<std::endl;
    int n;
    std::cin >> n;

    std::cout << "Jednakostranicni trougao: " << std::endl;
   for(int i = 0; i < n; i ++){
      for(int j = n - i ; j > 0; j--)  std::cout<<" ";
      for(int k = 0; k < 2 * i + 1; k++) std::cout<<"*";

    std::cout<<"\n";
   }
    return 0;
}
