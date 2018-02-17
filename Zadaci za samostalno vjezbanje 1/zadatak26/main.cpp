#include <iostream>
bool prost (int n){

    bool jeste = true;
    for(int i = 2; i <= n/2 ; i++)
        if(n % i == 0) {
                jeste = false;

        }
    return jeste;
}

int main()
{
    std::cout << "Unesite n: "  << std::endl;
    int n;
    std::cin >> n;
    int brojac{0};

     for(int i = 1;  ; i++){
        if (prost(i) == true  && i > 1) {brojac++;}
        if(brojac == n){
            std::cout<<"Broj: "<<i<<std::endl;
            break;
        }
    }
    std::cout<<"Brojac: "<<brojac<<std::endl;
   return 0;

}
