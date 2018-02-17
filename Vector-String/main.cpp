#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <set>

int broj_koraka(std::string s){
    int slovo (0);
    int i = 0;
    while  ( i < s.length() ){

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) slovo++;
    //    while( s[i] == ' ' || !( (s[i] >= 'a' && s[i] <= 'z') || (s[i]>= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') )) continue;

        i++;
    }
   return slovo;
}

// std::vector<std::set<std::string> >
void Razvrstavanje (std::vector<std::string> imena, int br_timova){

    if(br_timova < 1 || br_timova > imena.size())
        throw std::logic_error("Razvrstavanje nemoguce\n");

    //... SVA IMENA IZ VEKTORA ISKOPIRATI U LISTU
    std::list<std::string> lista;

   for(int i (0); i < imena.size(); i++){
       lista.push_back(imena[i]);
   }



    /*...KOLIKO TIM IMA CLANOVA
       int n = imena.size(), k = br_timova, vel_tim,broj;
        if(n % k == 0){ broj = n % k;  vel_tim = int(n / k) + 1;}
        else { broj = k - n % k  ; vel_tim = int(n /k);}
    */


    //...U TIMOVE RAZVRSTATI DJECU
  std::vector<std::set<std::string>> timovi;
        auto it = lista.begin();
        while(!lista.empty()){



       int n = imena.size(),k = br_timova;
       int broj = imena.size() % br_timova;


        for(int i = 0; i < broj;i++){
                 timovi.push_back(std::set<std::string>());
           while(timovi[i].size() <= int(n / k) + 1){
                timovi[i].insert(*it);
                   //...POMJERAJ IT I STAVLJAJ U SKUP
                   int b = broj_koraka(*it);
                   it = lista.erase(it);
                    if(it == lista.end()) it = lista.begin();
                    while(b - 1 > 0) it++;


            }

        }
    for(int i = broj; i < k ;i++){
             while(timovi[i].size() <= int(n / k) ){
                timovi[i].insert(*it);
                   //...POMJERAJ IT I STAVLJAJ U SKUP
                   int b = broj_koraka(*it);
                   it = lista.erase(it);
                    while(b - 1) it++;
        }


    }

        }
   //...ispis

    for(int i (0); i < timovi.size();i++){
        std::cout<<"Tim "<< i + 1 << ": ";
        for(auto skup : timovi[i]) std::cout<<skup<<" ";
        std::cout<<std::endl;
    }


}
int main ()
{


    //..BROJ_TIMOVA
    std::cout<<"Unesite broj djece: ";
    int broj_djece;
    std::cin >> broj_djece;

    std::cin.clear();
    std::cin.ignore(10000,'\n');

    std::string s;
    std::vector<std::string>imena;
    std::cout<<"\nUnesite imena djece:\n";


    for(int i (0); i < broj_djece ; i++){
         std::getline(std::cin,s);
         imena.push_back(s);

    }


    std::cout<<"Unesite broj timova: ";
    int broj_timova;
    std::cin >> broj_timova ;
    /*
    for(int i (0); i < imena.size();i++){
        std::cout<<imena[i]<<"| ";

    }
    */

    try{

      Razvrstavanje(imena,broj_timova);

    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;






}
