#include <iostream>
#include <stdexcept>
#include <initializer_list>

/* 4 TIPA STA SE MORA DEKLARISATI U KONSTRUKTORSKOJ INIC LISTI
    1.klasa u klasi inicijalizacija atributa unutrasnje klase izvodi se unutar konst.inc. vlasnicke klase
    2.kada je atribut referenca
    3.kada su konstantni atributi
    4.
    -kada je staticki konstantn atribut ne smije u inicijalizacijskoj listi u konstruktoru(poslije :)
*/


class VektorNd{
    int dimenzija;
    double *koordinate;

    void TestIndexa(int index) const {
        if(index < 1 || index > dimenzija) throw std::domain_error("Nekorektan index.\n");

    }
public:
    explicit VektorNd(int dimenzija);
    void PromijeniDImenziju(int nova_dimenzija);
    void POstaviKoordinatu(int index,double vrijednost);

   double DajKoordinatu(int index)const{
    TestIndexa(index);
    return koordinate[index - 1];
}

    double &DajKoordinatu(int index);
    void Ispisi() const {
        std::cout<<"{";
        for(int i = 0; i < dimenzija; i++){
            std::cout<<koordinate[i];
            if(i != dimenzija - 1) std::cout<<",";
        }
        std::cout<<"}";
    }
  ~VektorNd(){ if(koordinate == nullptr) return; delete[] koordinate; }
  //...FUNKCIJE CLANICE,NE PRIMAJU NISTA,JER IMAJU DIREKTAN PRISRUP KOORDINATAMA
  double *begin()   {  return koordinate;}
  double *end()     {  return koordinate + dimenzija;}

  VektorNd(std::initializer_list<double>lista);
  friend VektorNd ZbirVektora(const VektorNd &v1,const VektorNd &v2);
  VektorNd(const VektorNd &v);
  VektorNd (VektorNd &&v);

  VektorNd &operator=(const VektorNd &v);
  VektorNd &operator= (VektorNd v);
  VektorNd &operator=(const VektorNd &v);
  VektorNd &operator=(VektorNd &&v);
  VektorNd &operator=(VektorNd v);


};

VektorNd::VektorNd(int dimenzija): dimenzija(dimenzija),koordinate(new double[dimenzija]){
    std::fill(koordinate,koordinate+dimenzija,0);
}

void VektorNd::PromijeniDImenziju(int nova_dimenzija){
    //.. REALOKACIJA
    if(nova_dimenzija < dimenzija){
        double *novi_prostor (new double[nova_dimenzija]);
        std::copy(koordinate,koordinate + dimenzija,novi_prostor);
        std::fill(koordinate + dimenzija,koordinate + nova_dimenzija,0);
        koordinate = nullptr; koordinate = novi_prostor;
    }
    dimenzija = nova_dimenzija;
}

void VektorNd::POstaviKoordinatu(int index,double vrijednost){
    TestIndexa(index);
    koordinate[index - 1] = vrijednost;
}



  double &VektorNd::DajKoordinatu(int index){
    TestIndexa(index);
    return koordinate[index - 1];
  }

   VektorNd::VektorNd(std::initializer_list<double>lista): dimenzija(lista.size()), koordinate (new double [lista.size()]){
        std::copy(lista.begin(),lista.end(),koordinate);
   }

VektorNd ZbirVektora(const VektorNd &v1,const VektorNd &v2){
    if(v1.dimenzija != v2.dimenzija)
        throw std::domain_error("Dimenzije vektora razlicite!\n");
    VektorNd v3(v1);
    for(int i = 0; i < v1.dimenzija;i++)
    v3.koordinate[i] = v1.koordinate[i] + v2.koordinate[i];
    return v3;
}

VektorNd::VektorNd(const VektorNd &v) : dimenzija(v.dimenzija),koordinate(new double[v.dimenzija]){
    std::copy(v.koordinate,v.koordinate + v.dimenzija,koordinate);
}

// MOVE I PRIVREMENI OBJEKTI  - NPR. KADA SE NESTO POSALJE FUNKCIJI PO VRIJEDNOSTI
VektorNd::VektorNd (VektorNd &&v){
    dimenzija = v.dimenzija; koordinate = v.koordinate;
    v.koordinate = nullptr;
    v.dimenzija = 0;
}

//... OPERATOR DODJELE
/*VektorNd  &VektorNd::operator =(const VektorNd &v){
    double *novi_prostor (new double[v.dimenzija]);
    delete[]koordinate;

    dimenzija = v.dimenzija; koordinate = novi_prostor;
    std::copy(v.koordinate,v.koordinate + v.dimenzija,koordinate);
    return *this;
}

VektorNd &VektorNd::operator=(VektorNd v){
    std::swap(dimenzija,v.dimenzija);
    std::swap(koordinate,v.koordinate);
    return *this;
}
*/
VektorNd &VektorNd::operator=(const VektorNd &v){
    if(dimenzija < v.dimenzija){
        double *novi_prostor(new double [v.dimenzija]);
        delete[] koordinate;
        koordinate = novi_prostor;
    }
    dimenzija = v.dimenzija;
    std::copy(v.koordinate,v.koordinate + v.dimenzija,koordinate);

    return *this;
}

//.. POMJERAJUCI OPERATOR DODJELE
VektorNd &VektorNd::operator=(VektorNd &&v){
    //..obrise ono na sta je prije pokazivao
    // MORA SE PROVJERITI SAMODODJELA ZA POMJERAJUCI OPERATOR DODJELE
    if(&v != this){
    delete[]koordinate;
    dimenzija = v.dimenzija;
    kooordinate = v.koordinate;
    v.koordinate = nullptr;
    }
    return *this;
}

VektorNd &VektorNd::operator=(VektorNd v){
    std::swap(dimenzija,v.dimenzija);
    std::swap(koordinate,v.koordinate);
    return *this;
}
int main()
{
    try{
        /*VektorNd v1(2),v2(3);
        v1.POstaviKoordinatu(1,1);
        v1.POstaviKoordinatu(2,2);
        v2.POstaviKoordinatu(1,3);
        v2.POstaviKoordinatu(2,4);
        v2.POstaviKoordinatu(3,5);
        std::cout<<v1.DajKoordinatu(2)<<"|"<<v2.DajKoordinatu(3)<<std::endl;

        cout<<"V1"<<endl;
        v1.Ispisi();
        v1.DajKoordinatu(1) = 8;
        v1.Ispisi();

        VektorNd v3({1,2,3,4,5});
        cout<<"V3"<<endl;
        v3.Ispisi();
        VektorNd v4({2,3,4,5,6});
        /*... kako on zna da ispisuje samo koordinte kao atribut
        for(double x : v3){
            std::cout<<x<<" " ;
        }

        std::cout<<"\nKonstruktor kopije:\n";
        VektorNd v5 (ZbirVektora(v3,v4));
        v5.Ispisi();

        VektorNd v6(v5);
        v6.Ispisi();

        VektorNd b(std::move(v3));
        b.Ispisi();
        std::cout<<"Operator dodjele:\n";
        cout<<"V3"<<endl;
        v3.Ispisi();
        v4 = v3;
        cout<<"V4"<<endl;
        v4.Ispisi();

        VektorNd v3({1,2,3,4,5});
        VektorNd v4({2,3,4,5,6});

        v3 = v4;
        VektorNd v5 (ZbirVektora(v3,v4));
        VektorNd b(std::move(v3));
        b.Ispisi();
        v3.Ispisi();
        v5.Ispisi();
        */

        VektorNd v3({1,2,3,4,5});
        VektorNd v4({2,3,4,5,6});

        v3 = v4;
        v3.Ispisi();
    }catch(...){
        std::cout<<"Problemi sa memorijom!\n";
    }
    return 0;
}
