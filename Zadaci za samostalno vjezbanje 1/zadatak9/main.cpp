/*zadatak9*/
#include <iostream>
#include<cmath>
int main()
{
    std::cout << "Unesite broj: " << std::endl;
    int br;
    std::cin >> br;
//... dok je djelioc 2 ,ispisuj
       while(br % 2 == 0) {
        br /= 2;
        std::cout<<"2 ";
       }
//...trazi sa kojim je brojem jos djeljiv nas broj,i sve dok je djeljiv sa i, ispisuj i .
       for(int i = 3; i < std::sqrt(br); i = i + 2)
        {
            while(br % i == 0){
            std::cout<< i << " ";
               br /= i;
            }
        }
//...ukoliko postoji djelioc koji nije u intervalu od 3 do sqrt(3), i nije 2, a veci je od 2 onda ispisi i taj broj
        if(br > 2)
            std::cout<< br << " ";
    std::cout<<"\n";

    return 0;
}
