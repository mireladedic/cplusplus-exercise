#include <iostream>
#include <stdexcept>
int ** KreirajTrougao(int n){
    if(n <= 0) throw std::domain_error("Broj redova mora biti pozitivan!\n");

    try{
      int **a = new int *[n];
        for(int i (0); i < n; i++) a[i] = nullptr;

        try{
            for(int i (0); i < n; i++){
                a[i] = new int (i * 2 + 1);
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
            for(int i (0); i < n; i++) delete [] a[i];
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

        int **pok = KreirajTrougao(n);

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
