#include <iostream>
#include <string>
bool slovo(char c){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    return false;
}

int main()
{
    std::cout << "Unesite prvu recenicu:" << std::endl;
    std::string rec;
    std::getline(std::cin,rec);

    std::cout << "Unesite drugu recenicu:" << std::endl;
    std::string s;
    std::getline(std::cin,s);

    int slova{0};
    for(int i (0); i < rec.length();i++){

       while(!slovo(rec[i])) i++;

        while(slovo(rec[i]) && rec[i] != ' ' && i <rec.length() ){
          //  std::cout<<rec[i]<<" ? ";
            slova++;
            i++;
        }
    }

    int slovas {0};
    for(int i (0); i < s.length();i++){
        while(!slovo(s[i])) i++;

        while(slovo(s[i]) && s[i] != ' ' ){
          //  std::cout<<s[i]<<" ? ";
            slovas++;
            i++;
        }
    }
    std::cout<<"Broj slova: "<< slova <<" | "<< slovas <<std::endl;

    //...SPOJI DVA STRINGA U JEDAN STRING
    std::cout<<"Spojeni: \n";
    std::string spojeni = rec + s;
    for(int i (0); i < spojeni.size();i++){
        std::cout<<spojeni[i];
    }
    std::cout<<"\n";

    //... ISPISI DRUGI STRING OBRNUTO
    std::cout<<"Drugi string obrnuto: \n";
    for(int i = s.size() - 1; i >= 0; i--){
        std::cout<<s[i];
    }
    std::cout<<std::endl;

    //...POREDI RECENICE PO ABC PORETKU  ????

    return 0;
}
