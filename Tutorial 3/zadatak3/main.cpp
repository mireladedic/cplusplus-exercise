#include <iostream>
#include <vector>
#include <iomanip>

    std::vector<std::vector<int>> TablicaMnozenja(int m,int n){

        std::vector<std::vector<int>> mat;

        mat.resize(m);
        for(int i = 0; i < m; i++) mat[i].resize(n);

        for(int i = 1; i <= mat.size() ; i++){
            for(int j = 1; j <= mat[i-1].size(); j++){
                mat[i-1][j-1] = (i) * (j);
            }
        }

    /*
        mat.resize(m);
        for(int i = 1; i <= m;i++) mat[i].resize(n);

        for(int i = 1; i <= mat.size();i++){
            for(int j = 1; j <= mat[i].size(); j++){
                mat[i][j] = i * j;
            }
        }
    */
    return mat;
    }

int main()
{
    std::cout<<"Unesite m i n : \n";
    int m,n;
    std::cin >> m >> n;

    std::vector<std::vector<int>>matr = TablicaMnozenja(m,n);

    for(int i = 0; i < matr.size(); i++){
        for(int j = 0; j < matr[i].size(); j++){
            std::cout<<std::setw(4)<<matr[i][j]<< " ";
        }
        std::cout<<"\n";
    }
    return 0;
}
