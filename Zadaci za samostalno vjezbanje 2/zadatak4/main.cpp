#include <iostream>
bool fun (int n){

    int br = n;
    bool jednake = false;

        int prva = br % 10;
        while(n != 0){
            int cifra = n % 100;
                if(prva == cifra){
                    jednake = true;
                }
                n /= 10;
        }
    if(jednake) std::cout<<"Jednake su!"<<std::endl;
    else std::cout<<"Nisu jednake!"<<std::endl;

return jednake;
}
int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin>>n;
    fun(n);

return 0;
}
