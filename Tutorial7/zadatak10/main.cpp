#include <iostream>
#include <string>
#include <cctype>

int transf(std::string &s,char fun (char)){
    int br(0);
    for(int i (0); i < s.size(); i++){
        if(fun(s[i]) == s[i]){
            s[i] = '+';
            br++;
        }
    }
    return br;
}

int main()
{
    std::cout<<"Unesite string:\n";
    std::string s;
    std::getline(std::cin,s);

    int br = transf(s,[](char c ) -> char{
                       return std::tolower(c);
                    }
                    );

    for(int i (0); i < s.size(); i++){
        std::cout<<s[i]<<" | ";
    }
    return 0;
}
