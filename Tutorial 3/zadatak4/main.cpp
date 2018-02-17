#include <iostream>
#include <iomanip>
#include <vector>

    std::vector<std::vector<int>> PascalovTrougao(int n){
        std::vector<std::vector<int>> pascal;

        //... kreiranje matrice ;
        pascal.resize(n);
        for(int i = 0; i < n; i++) pascal[i].resize(i + 1);

        //...popunjavanje matrice
        for(int i = 0; i < pascal.size();i++){
            for(int j = 0; j < pascal[i].size();j++){
                if( j == 0 || i == j) pascal[i][j] = 1;
                else if(i > j) {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
        }
        return pascal;
        }

int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    std::vector<std::vector<int>>mat = PascalovTrougao(n);

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            std::cout<<std::setw(5)<<mat[i][j];
        }
        std::cout<<"\n";
    }
    return 0;
}
