#include <iostream>
#include <stdexcept>
class VektorNd{
    int dimenzija;
    double *koordinate;

    void TestIndex(int index) const{
        if(index < 1 || index > dimenzija) throw std::domain_error("Pogresan index!\n");
    }

public:
    explicit VektorNd(int dimenzija);// KONSTRUKTOR
    void PromijeniDimenziju(int nova_dimenzija); // METODA
    void PostaviKoordinatu(int index,double vrijednost); // METODA
    double DajKoordinatu(int index)const; // KONSTANTNA METODA
    double &DajKoordinatu(int index); // NEKONSTANTNA METODA
    void Ispisi()const; // METODA
    ~VektorNd(){delete[] koordinate;} // DESTRUKTOR
};
//... KONSTRUKTOR
VektorNd::VektorNd(int dimenzija) : dimenzija(dimenzija), koordinate(new double [dimenzija]){
    std::fill(koordinate,koordinate+dimenzija,0);
}

void VektorNd::PromijeniDimenziju(int nova_dimenzija){
    double *novo_mjesto = nullptr;
    if(VektorNd::dimenzija > nova_dimenzija){
        novo_mjesto = new double[nova_dimenzija];
        std::copy(koordinate,koordinate + dimenzija,novo_mjesto);
        std::fill(novo_mjesto + dimenzija,novo_mjesto + nova_dimenzija,0);
        delete[] koordinate;
        koordinate = nullptr;
    }else{
        dimenzija = nova_dimenzija;
    }
}

void VektorNd::PostaviKoordinatu(int index,double vrijednost){
    TestIndex(index);
    koordinate[index - 1] = vrijednost;
}

double VektorNd::DajKoordinatu(int index) const{
    TestIndex(index);
    return koordinate[index - 1];
}

double &VektorNd::DajKoordinatu(int index){
    TestIndex(index);
    return koordinate[index - 1];
}

void VektorNd::Ispisi()const{
    std::cout<<"{ ";
    for(int i = 0; i < dimenzija; i++){
        std::cout<< koordinate[i];
    if(i != dimenzija - 1) std::cout<<" , ";
    }
    std::cout<<"}";
}

int main()
{
    try{
        VektorNd v1(3),v2(2);
        v1.PostaviKoordinatu(1,5);
        v1.PostaviKoordinatu(2,4);
        v1.PostaviKoordinatu(3,3);
        v2.PostaviKoordinatu(1,8);
        v2.PostaviKoordinatu(2,9);
        v1.Ispisi();
        std::cout<<std::endl;
        v2.Ispisi();
        std::cout<<"\n" << v1.DajKoordinatu(2)<< " | "<<v2.DajKoordinatu(1);

    }catch(std::bad_alloc){
        std::cout<<"Problemi sa memorijom.\n";
    }
    return 0;
}
