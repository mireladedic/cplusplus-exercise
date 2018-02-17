#include <iostream>
int main()
{
    std::cout<<"Unesite n i m: " << std::endl;
    int n,m;
    std::cin >> n >> m;

    std::cout<<"Nacrtaj pravougaonik: " << std::endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == (m - 1) || j == (n - 1))
              {
                 std::cout<<"*" ;
              } else {
                 std::cout<<" ";
                }
        }
        std::cout<<"\n";
    }
    return 0;
}
