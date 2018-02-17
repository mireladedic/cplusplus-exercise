#include <iostream>
#include <vector>
#include <type_traits>

template<typename IterTip>
void RazmijeniBlokove(IterTip &pocetak,IterTip &izakraja,IterTip &poc){
    while(pocetak != izakraja){
    /*... NE POMIJERANJE ELEMNATA
          IterTip pomocna (std::move(pocetak));
      pocetak  (std::move(izakraja));
      izakraja (std::move(pomocna));
      pocetak ++;
      poc++;
*/
      //... ITERATORI ILI POKAZIVACI RAMJENA
      if(pocetak != izakraja){
      IterTip pomocna;

      *pomocna = *pocetak;
      *pocetak = *poc;
      *poc = *pomocna;

     // std::swap(*pocetak,*poc);
      pocetak++;
      poc++;

    }
    }
}

int main()
{

    std::vector<int>v1 {1,2,3,4,5};
    std::vector<int>v2{6,7,8,9,10};

  std::vector<int>::iterator it1 = v1.begin();
  std::vector<int>::iterator it2 = v1.end();
  std::vector<int>::iterator it3 = v2.begin();

  /*
  auto it1 = v1.begin();
   auto it2 = v1.end();
   auto it3 = v2.begin();
   */
   RazmijeniBlokove<std::vector<int>::iterator>(it1,it2,it3);


for(int i = 0; i < v1.size(); i++) std::cout<<"| "<<v1[i];
std::cout<<"\n";
for(int i = 0; i < v2.size(); i++) std::cout<<"| "<<v2[i];


    return 0;
}
