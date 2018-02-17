#include <iostream>
#include <string>

bool slovo(char c){
    if( ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) )
        return true;
    return false;
}

std::string funkcija (std::string s, int br){
    std::string lett;
    char pocetak,kraj;
    int broj {0};
    for(int i (0); i < s.size();i++){

    if(slovo(s[i])){
            pocetak = i;
        }

        while(slovo(s[i])){
            i++;
            if(i == s.size() - 1) kraj = i - 1;
        }
        kraj = i;
        broj++;
        if(broj == br) {
        lett = s.substr(pocetak,kraj );
        break;
        }
        i = kraj;

    }

    return lett;
}

int main()
{
   int redni;
    std::cout<<"Unesite broj: \n";
    std::cin>>redni;

    std::cin.ignore(10000,'\n');

    std::cout<<"Unesite recenicu:\n";
    std::string s;
    std::getline(std::cin,s);

    std::string rijec = funkcija(s,redni);

    for(int i (0); i < rijec.size(); i++){
        std::cout<<rijec[i]<<" | ";
    }
    return 0;
}
