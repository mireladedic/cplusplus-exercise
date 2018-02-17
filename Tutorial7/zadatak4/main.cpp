#include <iostream>
#include <set>

template<typename Tip>

std::set<Tip> Unija(std::set<Tip>&s1,std::set<Tip>&s2){
    std::set<Tip>s;
    //...PRODJI KROZ ELEMENTE SKUPA S1 I S2 TE DODIJELI SKUPU S

    auto it = s1.begin();
    for(it; it != s1.end();it++){
        s.insert(*it);
    }

    auto it1 = s2.begin();
    for(it1;it1 != s2.end();it1++){
        s.insert(*it1);
    }

    std::cout<<"unija:\n";
    for(auto it2 = s.begin(); it2 != s.end();it2++){
        std::cout<<*it2<<" | ";
    }

    return s;
}
template<typename tip>
std::set<tip> Presjek(std::set<tip>&s1,std::set<tip>&s2){
     std::set<tip>s;
    //...PRODJI KROZ ELEMENTE SKUPA S1 I S2 AKO SU ISTI TE DODIJELI SKUPU S

   for(auto it1 = s1.begin(); it1 != s1.end();it1++){
        for(auto it2 = s2.begin(); it2 != s2.end(); it2++){
            if(*it1 == *it2){
                s.insert(*it1);
            }
        }
   }
    std::cout<<"\npresjek:\n";
    for(auto it = s.begin(); it != s.end();it++){
        std::cout<<*it<<" | ";
    }

    return s;

}


int main()
{
    //....SKUP
    std::set<std::string>s1;
    std::cout<<"Unesite elemente skupa1 : \n";
    for(;;){
        std::string str;
        std::getline(std::cin,str);
        if(str == std::string()) break;

        s1.insert(str);
    }

    //...SKUP
    std::set<std::string>s2;
    std::cout<<"Unesite elemente skupa2:\n";
    for(;;){
        std::string str;
        std::getline(std::cin,str);
        if(str == std::string()) break;

        s2.insert(str);
    }

    std::set<std::string>s = Unija(s1,s2);
    std::set<std::string>c = Presjek(s1,s2);
    return 0;
}
