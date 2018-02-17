#include <iostream>
#include<stdexcept>
#include<initializer_list>

class VektorNd{
    int dimenzija;
    double *koordinate;
    int *pokazivac_na_brojac;

    void TestIndexa (int index) const{
        std::range_error("Nekorektan index\n");
    }
public:
    explicit VektorNd(int dimenzija);
    ~VektorNd();
    VektorNd(const VektorNd &v);
    VektorNd &operator=(const VektorNd &v);
    VektorNd(std::initializer_list<double>lista);

     void Ispisi() const {
        std::cout<<"{";
        for(int i = 0; i < dimenzija; i++){
            std::cout<<koordinate[i];
            if(i != dimenzija - 1) std::cout<<",";
        }
        std::cout<<"}";
    }

 };

VektorNd::VektorNd(int dimenzija) : dimenzija(dimenzija),koordinate(new double[dimenzija]),pokazivac_na_brojac(new int(1)){
    std::fill(koordinate,koordinate + dimenzija,0);
}
VektorNd::VektorNd(std::initializer_list<double>lista) : dimenzija(lista.size()),koordinate(new double[lista.size()]),
                    pokazivac_na_brojac(new int(1)){
                        std::copy(lista.begin(),lista.end(),koordinate);
                    }
//... KONSTRUKTOR KOPIJE
VektorNd::VektorNd(const VektorNd &v): dimenzija(v.dimenzija), koordinate(v.koordinate),pokazivac_na_brojac(v.pokazivac_na_brojac){
        (*pokazivac_na_brojac)++;
}
//... DESTRUKTOR
VektorNd::~VektorNd(){
    //... DESTRUKTOR UMANJUJE BROJAC ZA 1 PA UKOLIKO TAD BROJAC DOSTIGNE NULU BRISE ELEMENT
    if(--(*pokazivac_na_brojac) == 0){
        delete[] koordinate;
        delete pokazivac_na_brojac;
    }
}
//... OPERATOR DODJELE
VektorNd &VektorNd::operator=(const VektorNd &v){
/*    UMANJUJE BROJAC ZA 1 RESURSIMA PRIDRUZENIM OBJEKTU SA LIJEVE STRANE  I VRSI OSLOBADJANJE RESURSA U SLUCAJU DA JE BROJAC DOSTIGAO NULU
    BROJAC PRISTUPA RESURSIMA SA DESNE STRANE UVECAVA ZA 1 I NAKON TOGA IZVRSI PLITKO KOPIRANJE
*/
    (*v.pokazivac_na_brojac)++;
    if(--(*pokazivac_na_brojac) == 0){
        delete[] koordinate;
        delete pokazivac_na_brojac;
    }

    dimenzija = v.dimenzija;
    koordinate = v.koordinate;
    pokazivac_na_brojac = v.pokazivac_na_brojac;

    return *this;
}

int main()
{
   VektorNd v1({1,2,3}), v2{4,5,6};
   VektorNd v(v1);
   v1.Ispisi();
   v1 = v2;
   v1.Ispisi();
    return 0;
}
