#include <iostream>

int main()
{
    std::cout << "Unesite n: " << std::endl;
    int n;
    std::cin >> n;
    while(n < 5 || n > 24 || !std::cin){
        std::cin.clear();
        std::cin.ignore('10000','\n');
        std::cout<<"Unesite n (ne manji od 5, ne veci od 24!): "<<std::endl;
        std::cin>>n;
        }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++){

            if((i == 0 && j == 0) || (i == n - 1 && j == 0) || (j == 2 * n - 1 && i == 0) || (i == n - 1 && j == 2 * n - 1))            std::cout<<"+";
            else  if ((i == 2 && j == 3) || (i == 2 && j == 2 * n - 3) || (j == 3 && i == n - 3) || (j == 2 * n - 3 && i ==  n - 3))    std::cout<<"+";

            else if(i == 0 || i == n - 1 )                                  std::cout<<"-";
            else if((i == 2 || i == n - 3) && j > 3 && j < 2 * n - 3)       std::cout<<"-";

            else if(j == 0 || j == 2 * n - 1 )                              std::cout<<"|";
            else if( (j == 3 || j == 2 * n - 3) && i > 2 && i < n - 3)      std::cout<<"|";

            else    std::cout<<" ";
            }
        std::cout<<"\n";
    }

    return 0;
}
