#include <iostream>
bool prost (int n){

    bool jeste = true;
   for(int i = 2; i <= n/2; i++)
    if(n % i == 0) jeste = false;

   return jeste;

}

int main()
{
    std::cout << "Unesite opseg n i m : " << std::endl;
    int n,m;
    std::cin >> n >> m;

    std::cout<<"Prosti brojevi: "<<std::endl;
    for(int i = n; i < m ; i++){
        if ( prost(i) == true  && i > 1) std::cout<< i << " ";
    }
    return 0;
}
