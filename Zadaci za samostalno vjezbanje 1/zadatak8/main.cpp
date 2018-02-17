/* zadatak8 */
#include <iostream>
int main()
{
    std::cout << "Unesite 6 brojeva: " << std::endl;
    int br;
    bool pozitivan = true,paran = true;

    for(int i = 0 ; i < 6; i++){
        std::cin >> br;
       if(br < 0)  pozitivan = false;
       if(br % 2 != 0 ) paran = false;
    }

    if(pozitivan){
        if(paran){ std::cout<<"Svi pozitivni,svi parni."<<std::endl;}
        else{ std::cout<<"Svi pozitivni,postoji neparni."<<std::endl;}
    }else{
        if(paran){ std::cout<<"Negativan,svi parni."<<std::endl;}
        else{ std::cout<<"Negativan,svi neparni."<<std::endl;}
    }

    return 0;
}
