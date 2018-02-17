#include <iostream>
#include <stdexcept>
#include <vector>
#include <type_traits>
#include <vector>

template<typename iterTip>
auto KreirajIzvrnutiNiz(typename std::vector<iterTip>::iterator pocetak,typename std::vector<iterTip>::iterator izakraja) -> (std::remove_reference<decltype (*pocetak)>::type)** {

    iterTip *niz = nullptr;
    try{

        niz =  new iterTip [izakraja-pocetak];
    while(pocetak != izakraja){
        for(int i (0); i < (izakraja-pocetak); i++)
            niz[i] = *pocetak++;

    }


    for(int i = 0; i < n;i++){
        std::cout<<"| "<<niz[i];
    }

    return niz;

    }catch(std::bad_alloc){
      delete[]niz;
      std::cout<<"Neuspjela Alokacija!\n";
    }

}

int main()
{
    std::cout << "Koliko zelite elemenata: " << std::endl;
    int n;
    std::cin>>n;

    std::vector<double>v;
    for(int i = 0; i < n; i++){
        int br;
        std::cin>>br;
        v.push_back(br);
    }

  auto  pok = KreirajIzvrnutiNiz(std::begin(v),std::end(v));

   std::cout<<"poziv funkcije: \n";
   for(int i (0); i < n;i++){
    std::cout<<pok[i]<<" ";
   }

    return 0;
}
