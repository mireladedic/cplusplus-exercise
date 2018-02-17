#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>

//template<typename TipElemenata,typename Kontejner,typename kontejner>
//typedef vector<vector<T>> vektorvektora;
// Kontejner<Kontejner<T>>
/*
auto KreirajDinamickuKopiju2D(typename Kontejner<kontejner<TipElemenata>> mat) -> std::remove_reference(decltype(mat[i][j])) {
    //...DINAMICKA ALOKACIJA 2D STRUKTURE
    int brojredova{0},brojkolona{0};
    for(int i = 0; i < mat.size();i++) {
        brojredova++;
        for(int j = 0; j < mat[i].size();j++)
            brojkolona++;
    }

    std::cout<<"| "<<brojredova<<"| "<<brojkolona>>std::endl;
    for
    try{

        TipElementa ** dd = new TipElementa *[brojredova];
        for(int i (0); i < brojredova; i++){
            dd[i] = nullptr;
        }

        try{
            for(int i(0); i < brojredova; i++){
                dd[i] = new TipElemenata [brojkolona];
            }

            //...PREPISI ELEMENTE....
            for(int i = 0; i < mat.size();i++){
                for(int j = 0; j < mat[i].size();j++){
                    dd[i][j] = mat[i][j];
                }
            }



           return dd;


        }catch(std::bad_alloc){
            for(int i(0); i < brojredova;i++) delete[] dd[i];
            delete[] dd;
            std::cout<<"Neuspjela alokacija!";
        }
    }catch(...){
        std::cout<<"Nedovoljno memorije!\n";
    }



}
*/
int main()
{
    std::cout<<"Unesite n:\n";
    int n;
    std::cin >> n;
    int l;
    std::vector<std::vector<int>> mat;
    std::cout<<"Unesite elemente:\n";
    for(int i (0); i < n; i++){
            mat.push_back(std::vector<int>())
        for(int k = 0; k < n; k++){
            std::cin>>l;
              mat[i].push_back(l);
        }
    }
    /*
    int brojredova{0},brojkolona{0};
    for(int i = 0; i < mat.size();i++) {
        brojredova++;
        for(int j = 0; j < mat[i].size();j++)
            brojkolona++;
    }

    std::cout<<"| "<<brojredova<<"| "<<brojkolona<<std::endl;
  // auto pok =  KreirajDinamickuKopiju2d(mat);
*/
    return 0;
}
