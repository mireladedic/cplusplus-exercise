/* zadatak1 */
#include <iostream>
int main()
{
    std::cout << "Unesite prvo vrijeme: " << std::endl;
    int hours,minutes,seconds;
    std::cin >> hours >> minutes >> seconds;

    std::cout<< "Unesite drugo vrijeme: " << std::endl;
    int h,m,s;
    std::cin >> h >> m >> s;

    int sumsec {0};
    sumsec = hours * 3600 + minutes * 60 + seconds;
    std::cout<<"Prvo vrijeme u sekundama: " << sumsec <<std::endl;

    int ukupsek {0};
    ukupsek = h * 3600 + m * 60 + s;
    std::cout<<"Drugo vrijeme u sekundama: "<<ukupsek << std::endl;

    int razlika;
    if(sumsec > ukupsek) razlika = sumsec - ukupsek;
    if(ukupsek > sumsec) razlika = ukupsek - sumsec;
    std::cout<<"Razlika sekundi: " << razlika << std::endl;

    // GRESKA       ???
     int sati = int (razlika / 3600);
     double ostatakodsati = (razlika/3600) - sati;
     int  minute = int (ostatakodsati * 60);
     double ostatakodminuta = (ostatakodsati * 60) - minute;
     int  sekundi = ostatakodminuta * 60;

    std::cout<<"Imedju dva vremenska trenutka proteklo je " << sati << " sati , " << minute << " minuta, " << sekundi << "  sekundi\n";

    return 0;
}
