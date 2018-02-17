#include <iostream>
#include <stdexcept>

class digitalni_sat{
    int sati,minute,sekunde;

    static int DaLiJeIspravno(int sati ,int minute ,int sekunde) {
        if(sati < 1 || sati > 24 || minute < 1 || minute > 60 || sekunde < 1 || sekunde > 60) return 0;
        return 1;
    }

public:
   void  Postavi(int sati,int minute,int sekunde) {

        if(!DaLiJeIspravno(sati,minute,sekunde)) throw std::domain_error("Neispravno vrijeme.");

        sati=sati;
        minute=minute;
        sekunde=sekunde;
    }

    void PostaviNormalizirano(int sat,int mint,int sek){
        if(!DaLiJeIspravno(sat,mint,sek)){
            //...ISPRAVI VRIJEME

        }
    }
};

int main()
{
    digitalni_sat sat;
    sat.Postavi(1,2,3);
    return 0;
}
