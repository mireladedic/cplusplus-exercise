#include <iostream>
#include <stdexcept>
int ** KreirajTrougaoKontinualna(int n){
    if(n <= 0) throw std::domain_error("Broj redova mora biti pozitivan!\n");

    try{
      int **a = new int *[n];
        for(int i (0); i < n; i++) a[i] = nullptr;

        try{
        //...prvo u petlji saberi broj elemenata svih redova,I TU sumu stavi u new int
            int sum {0};
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 2 * i + 1; j++){
                    sum += 1;
                }
            }
            std::cout<<"s = "<<sum<<"\n";

            a[0] = new int [2 * n + 1];
            for(int i (1); i < n; i++){
                a[i] = a[i - 1] + 2 * i + 1;
            }
            //...POPUNI MATRICU...
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 2 * i + 1; j++){

                    if(j == 0) a[i][j] = i + 1;
                    else if(i == j) a[i][j] = 1;
                    else if(i > j) a[i][j] = a[i - 1][j -1];
                    else a[i][j] = a[i][j - 1] + 1;
            }
            }

        return a;
        }catch(std::bad_alloc){
            //...ALOKACIJA NIJE USPJELA...
            delete[] a;
            throw;

        }

    }catch(...){
        std::cout<<"Nedovoljno memorije !\n";
    }


}

int main()
{
    std::cout << "Koliko zelite redova: " << std::endl;
    try{
        int n;
        std::cin>> n;

        int **pok = KreirajTrougaoKontinualna(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2 * i + 1; j++){
                std::cout<<pok[i][j]<<" ";
            }
            std::cout<<"\n";
        }
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    return 0;
}
