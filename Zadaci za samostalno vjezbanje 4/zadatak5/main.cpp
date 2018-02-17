#include <iostream>


void SumeCifara(int n, int n_par,int n_nepar){
    int broj = n;
    int s_par (0),s_nepar(0);

    while(broj != 0){
        int c = broj % 10;

        if(c % 2 == 0){
            s_par += c;
        }else{
            s_nepar += c;
        }

        broj /= 10;
    }
    n_par = s_par;
    n_nepar = s_nepar;

    std::cout<<n_par <<" | "<<n_nepar<<std::endl;

}
int main() {
    int broj;
    std::cout<<"Unesite broj:\n";
    int par,nepar;

    while(std::cin >> broj && broj != 0){
        SumeCifara(broj,par = 0,nepar = 0);
    }
    return 0;
}
