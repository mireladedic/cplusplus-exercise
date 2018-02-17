#include <iostream>
#include <list>
#include <string>
#include <algorithm>
//.........PRAZAN STRING ! NE RADI
int main()
{
    std::string s;
    std::list<std::string>lista;

    std::cout<<"Unesite recenice u listu:\n";
    for(int i = 0; i < 3; i++){
        std::getline(std::cin,s);
        lista.push_back(s);
    }

    std::list<std::string>novalista(lista.size());

    std::transform(lista.begin(),lista.end(),novalista.begin(),[](std::string s) -> std::string {
                                                                    int br (0);
                                                                    for(int i = 0; i < s.size(); i++){
                                                                        if( !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s [i] <= '9'))){
                                                                                br++;
                                                                        }

                                                                    }
                                                                    std::string prazan = std::string();
                                                                    if(br < 7) return s;
                                                                    else return prazan;

                                                                    });





    std::cout<<"\nTransformirana lista:\n";
    for(auto x : novalista){
        if(x == std::string()) continue;
        std::cout<< x << std::endl;
    }
    return 0;
}
