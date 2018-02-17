#include <iostream>
bool DaLiJeProst(int n){
    bool jeste = true;
    for(int i = 2; i <= n/2 ; i++)
    {
        if(n % i == 0) jeste = false;
    }
    return jeste;
}
int main()
{
    std::cout<<"Unesite a i b : "<<std::endl;
    int a, b;
    std::cin >> a >> b;

    for(int i = a; i <=b ; i++){
        if(DaLiJeProst(i) == true) {std::cout<<"Broj "<< i << " je prost. \n"; }
        else {std::cout<<"Broj "<< i << " nije prost. \n";}

    }
    return 0;
}
