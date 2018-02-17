#include <iostream>
#include <list>
template<typename UporediviTip>
std::list<UporediviTip> SortirajListu(std::list<UporediviTip> l){
    //...NOVA LISTA
    std::list<UporediviTip>nova;
    //...PRODJI KROZ LISTU...
/* ZA LISTU NE RADI <,> TJ ZA TE ITERATORE KOJI POKAZUJU NA LISTU
    auto it1(l.begin());
    auto it2 (l.begin());
    while(it1 != l.end()){
         it2++;
    if(*it1 > *it2 && it2 < l.end()) nova.push_back(*it2);
    it1++;

   }
*/


    auto it1 = l.begin();


    for(it1; it1 != l.end(); it1++) {
        for(auto it2 = it1; it2 != l.end(); it2++) {
            if(*it1 < *it2) {
                auto temp = *it2;
                *it2 = *it1;
                *it1 = temp;
            }
        }
    }

    for(auto it = l.begin(); it != l.end();it++){
        nova.push_back(*it);
    }
    return nova;
}
int main()
{
    //... UNOS ELEMENATA LISTE....
    std::list<int>lista;
    std::cout<<"Unesite elemente liste:\n";
    for(;;){
        int x;
        std::cin>>x;
        if(x == 0) break;
        lista.push_back(x);
    }
    //....POZIV FUNKCIJE....
    std::list<int>l = SortirajListu(lista);
    std::cout<<"Poziv funkcije:\n";
    std::list<int>::iterator it;
    for(it = l.begin(); it != l.end();it++){
        std::cout<<*it<<" | ";
    }

    return 0;
}
