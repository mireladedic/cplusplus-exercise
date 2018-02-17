/* zadatak4 */
#include <iostream>
#define fiksnapretplata 10
int main()
{
    std::cout << "Unesite broj sati pretplate na internet: " << std::endl;
    int brojsati;
    std::cin >> brojsati;

    double iznos1 = fiksnapretplata + (brojsati * 0.5);
    double iznos2 = brojsati * 0.8;
    std::cout<<"iznos1: " << iznos1 << "\niznos2: " << iznos2 << std::endl;

    double min = iznos1;
    if(iznos2 < min) {
        min = iznos2;
        std::cout<<"Isplati se uzeti firmu dva jer je mjesecna pretplata jednaka: " << iznos2 << std::endl;
    }else{
        std::cout<<"Uzmite firmu jedan jer je mjesecna pretplata jednaka: "<< iznos1 << std::endl;
    }
    return 0;
}
