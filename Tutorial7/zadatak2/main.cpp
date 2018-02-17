#include <iostream>
#include <string.h>
#include <algorithm>
//... PRIMA POKAZIVACE NA POCETKE RECENICA - FUNKCIJA KRITERIJA
bool IspredPoASCIIKodovima(const char *a, const char * b){
    //...   true RASTUCI POREDAK
    strcmp(a,b) < 0;
}
int main()
{
    std::cout<<"Unesite broj recenica:\n";
    int n;
    std::cin >> n;

    std::cin.ignore(10000,'\n');

    //...DINAMICKI ALOCIRA NIZ POKAZIVACA NA RECENICE...
    char ** recenice (new char * [n]);
    std::cout<<"Unesite niz recenica:\n";
    //....DEKLARISEM NIZ RECENICA
    char recenica[100];
    //... UNESI RECENICE - PRODJEM KROZ NIZ POKAZIVACA, UNESEM RECENCE
    for(int i(0); i < n;i++){
    std::cin.getline(recenica,sizeof recenica);
    //...NIZ POKAZIVACA NA RECENICE ,DINAMICKI ALOCIRAM PROSTOR ZA TE RECENICE
    recenice[i] = new char[strlen(recenica) + 1];
    //...KOPIRAM RECENICE
    strcpy(recenice[i],recenica);
    }
    //... SORTIRAJ RECENICE - IZMJENI POKAZIVACE NA NJIH
/*
    for(int i (0); i < n; i++){
            for(int j (0); j < n; j++) {
                if(IspredPoASCIIKodovima(recenice[i],recenice[j])){
                        char *pomocni = recenice[i];
                        recenice[i] = recenice[j];
                        recenice[j] = pomocni;
                }
            }
    }
*/
    //... OPADAJUCI POREDAK
    std::sort(recenice,recenice + n,IspredPoASCIIKodovima);
    std::cout<<"Sortirano:\n";
    for(int i = 0; i < n;i++){
        std::cout<<recenice[i]<<std::endl;
    }
    return 0;
}
