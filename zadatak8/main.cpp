#include <iostream>
#include <string>
#include <memory>
class ApstraktniLik{
protected:
    std::string vrsta,boja;
public:
    ApstraktniLik(std::string vrsta,std::string boja): vrsta(vrsta),boja(boja){}
    std::string DajBoju () const {  return boja; }

    virtual ApstraktniLik *DajKopiju()const = 0;

    virtual ~ApstraktniLik(){}
    virtual double DajObim()const{return 0;}
    virtual double DajPovrsinu()const {return 0; }
    virtual void Ispisi() const {
        std::cout<< vrsta <<" | " << boja << " | "<<DajObim()<<" | "<<DajPovrsinu()<<std::endl;
    }
};

class Krug : public ApstraktniLik{
    double r;
    static constexpr double  PI = 3.1415;
public:
    Krug(std::string boja,double poluprecnik) : ApstraktniLik("Krug",boja), r(poluprecnik) {}
    double DajObim() const  override { return 2 * PI * r; }
    double DajPovrsinu () const override { return r * r * PI;}
    ApstraktniLik *DajKopiju()const override{ return (new Krug(*this)); }
};

class Pravougaonik: public ApstraktniLik{
    double a,b;
public:
    Pravougaonik(std::string boja,double a ,double b) : ApstraktniLik("Pravougaonik",boja), a(a) , b(b){}
    double DajObim() const override {return 2 * (a + b) ; }
    double DajPovrsinu() const override {return a * b; }
    ApstraktniLik *DajKopiju()const override{ return (new Pravougaonik(*this)); }
};

class Trougao : public ApstraktniLik{
    double a,b,c;
public:
    Trougao(std::string boja,double a, double b, double c) : ApstraktniLik("Trougao", boja), a (a) , b(b) , c(c){}
     ApstraktniLik *DajKopiju()const override{ return new Trougao(*this); }
};

class Kvadrat : public Pravougaonik{

public:
    Kvadrat(std::string boja,double a) : Pravougaonik(boja,a,a){
        ApstraktniLik::vrsta = "Kvadrat";
    }
};

class KolekcijaLikova{
    int broj_likova;
    int kapacitet;
    ApstraktniLik **likovi;
public:
    explicit KolekcijaLikova(int kapacitet): broj_likova(0),kapacitet(kapacitet),likovi(new ApstraktniLik*[kapacitet]{}){}
    ~KolekcijaLikova();

    KolekcijaLikova(const KolekcijaLikova &k);
    KolekcijaLikova(KolekcijaLikova &&k);
    //KolekcijaLikova(KolekcijaLikova k);

    KolekcijaLikova &operator= (const KolekcijaLikova &k);
    KolekcijaLikova &operator= (KolekcijaLikova &&k);
  //  KolekcijaLikova &operator= (KolekcijaLikova k);

    void DodajLik(ApstraktniLik *lik);
    void DodajKrug(std::string boja,double r);
    void DodajPravougaonik(std::string boja,double a,double b);
    void DodajTrougao(std::string boja,double a, double b,double c);
    void IspisiKolekciju()const;
};

KolekcijaLikova::~KolekcijaLikova(){
    for(int i = 0; i < broj_likova;i++) delete likovi[i];
    delete[]likovi;
}

void KolekcijaLikova::DodajLik(ApstraktniLik *lik){
    if(broj_likova > kapacitet){
        throw std::range_error("Prekoracen kapacitet\n");
        delete lik;
    }
    likovi[broj_likova++] = lik;
}

void KolekcijaLikova::IspisiKolekciju()const {
    for(int i = 0; i < broj_likova;i++) likovi[i]->Ispisi();
}
//... KONSTRUKTOR KOPIJE
KolekcijaLikova::KolekcijaLikova(const KolekcijaLikova &k): broj_likova(k.broj_likova),kapacitet(k.kapacitet),likovi(new ApstraktniLik*[k.kapacitet]{}) {
    //..NAPRAVIMO ISTO KAO I K
    try{
        for(int i = 0; i < broj_likova;i++)
            likovi[i] = k.likovi[i]->DajKopiju();
        }catch(...){
            for(int i = 0; i < broj_likova;i++ )
                delete likovi[i];
            delete[]likovi;
            throw ;
        }
    }


//...OPERATOR DODJELE
    KolekcijaLikova &KolekcijaLikova::operator=(const KolekcijaLikova &k){
        //DINAMICKI ALOCIRAMO VEKTOR POKAZIVACA NA NOVOM MJESTU
        ApstraktniLik **novi_prostor(new ApstraktniLik*[k.kapacitet]{});
        // DINAMICKI ALOCIRAMO I OSTALE ELEMENTE
        try{
            for(int i = 0; i < broj_likova;i++){
                novi_prostor[i] = k.likovi[i]->DajKopiju();
            }
        }catch(...){
            for(int i = 0; i < broj_likova;i++){
                delete novi_prostor[i];
            }
            delete[]novi_prostor;
            throw;
        }
        // OBRISEMO ONO NA STA JE RANIJE POKAZIVAO
        for(int i = 0; i < broj_likova;i++) delete likovi[i]; delete[]likovi;
        //KOPIRAMO SVE NOVO
        likovi = novi_prostor;
        kapacitet = k.kapacitet;
        broj_likova = k.broj_likova;
        //VRATIMO TAJ NOVI
        return *this;
    }

/*... KONSTRUKTOR KOPIJE KOPIRAJ I RAZMJENI
KolekcijaLikova::KolekcijaLikova(KolekcijaLikova k){
    std::swap(kapacitet,k.kapacitet);
    std::swap(broj_likova,k.broj_likova);
    std::swap(likovi,k.likovi);
    return *this;
}
*/
//...POMJERAJUCI KONSTRUKTOR KOPIJE
KolekcijaLikova::KolekcijaLikova(KolekcijaLikova &&k): likovi(k.likovi), kapacitet(k.kapacitet),broj_likova(k.broj_likova)  {
    //...UKRADE RESURSE
    k.likovi = nullptr;
    k.broj_likova = 0;
}

//... OPERATOR DODJELE POMJERAJUCI
KolekcijaLikova &KolekcijaLikova::operator=(KolekcijaLikova &&k){
    std::swap(broj_likova,k.broj_likova);
    std::swap(kapacitet,k.kapacitet);
    std::swap(likovi,k.likovi);
    return *this;
}
/*
KolekcijaLikova &KolekcijaLikova::operator=(KolekcijaLikova k){
    std::swap(broj_likova,k.broj_likova);
    std::swap(kapacitet,k.kapacitet);
    std::swap(likovi,k.likovi);
    return *this;
}
*/
void KolekcijaLikova::DodajKrug(std::string boja,double r){
    KolekcijaLikova::DodajLik(new Krug(boja,r));
}
void KolekcijaLikova::DodajPravougaonik(std::string boja,double a,double b){
    KolekcijaLikova::DodajLik(new Pravougaonik(boja,a,b));
}
void KolekcijaLikova::DodajTrougao(std::string boja,double a, double b,double c){
    KolekcijaLikova::DodajLik(new Trougao(boja,a,b,c));
}
class PolimorfniLik{ // heterogena klasa
    ApstraktniLik *pokazivac_na_lik;
    void Test()const{
        if(!pokazivac_na_lik) throw std::logic_error("Nema tog lika!\n");
    }

public:
    //.. KONSTRUKTOR SA JEDNIM PARAMETROM
    PolimorfniLik():pokazivac_na_lik(nullptr){}

    ~PolimorfniLik(){ delete pokazivac_na_lik; }

    PolimorfniLik(const ApstraktniLik &lik) : pokazivac_na_lik(lik.DajKopiju()){}

    PolimorfniLik(const PolimorfniLik &lik){
        if(!lik.pokazivac_na_lik) pokazivac_na_lik = nullptr;
        else pokazivac_na_lik = lik.pokazivac_na_lik->DajKopiju();
    }

    PolimorfniLik(PolimorfniLik &&lik){
      pokazivac_na_lik = lik.pokazivac_na_lik;
      lik.pokazivac_na_lik = nullptr;
    }

    PolimorfniLik &operator=(const PolimorfniLik &lik){
        ApstraktniLik *pokazivac_na_novi_prostor(nullptr);
        if(lik.pokazivac_na_lik != nullptr) pokazivac_na_novi_prostor = lik.pokazivac_na_lik->DajKopiju();
        delete pokazivac_na_lik;
        pokazivac_na_lik = pokazivac_na_novi_prostor;
        return *this;
    }

    PolimorfniLik &operator=(PolimorfniLik &&lik){
        std::swap(pokazivac_na_lik,lik.pokazivac_na_lik);
        return *this;
    }

    double DajObim(){
        Test();
        return pokazivac_na_lik->DajObim();
    }

    double DajPovrsinu(){
        return pokazivac_na_lik->DajPovrsinu();
    }

    void Ispisi() const{
        Test();
        pokazivac_na_lik->Ispisi();
    }
};
int main()
{
    /*
   Pravougaonik p("Crvena",5,4);
   Krug k ("Plava",3);
   std::cout<<p.DajBoju()<<" | "<<p.DajObim()<<" | "<<p.DajPovrsinu()<<std::endl;

   std::cout<<k.DajBoju()<<" | "<<k.DajObim()<<" | "<<k.DajPovrsinu()<<std::endl;

   p.Ispisi();
   k.Ispisi();
*/
/* PRIMJENA POLIMORFIZMA SA POKAZIVACIMA
    std::shared_ptr<ApstraktniLik>lik;
    lik = std::make_shared<Pravougaonik>("Crvena",5,4);
    lik->Ispisi();

    lik = std::make_shared<Krug>("Zelena",3);
    lik->Ispisi();
*/
/* DEFINICIJA PRIMJERAKA APSTRAKTNE KLASE = 0
    ApstraktniLik lik("NekakavLik","Zelena");
    ApstraktniLik *dinamicki_alociran_apstraktni_lik(new ApstraktniLik("NekakavLik","Zelena"));
    std::shared_ptr<ApstraktniLik>pametni_pokazivac_dinamicki_aloc_aps_lik(std::make_shared<ApstraktniLik>("NekakavLik","Zelena"));
    lik.Ispisi();
    dinamicki_alociran_apstraktni_lik->Ispisi();
    pametni_pokazivac_dinamicki_aloc_aps_lik->Ispisi();
*/
/* HETEROGENI NIZ NEPRAVI
    std::shared_ptr<ApstraktniLik>likovi[2]{ std::make_shared<Pravougaonik>("Plavi",5,4),std::make_shared<Krug>("Zuti",3)};
    for(int i = 0; i < 2; i++) likovi[i]->Ispisi();
*/
/*
    KolekcijaLikova likovi(20);
    likovi.DodajPravougaonik("Crveni",5,4);
    likovi.DodajKrug("Zuti",3);
    likovi.DodajTrougao("Zeleni",1,2,3);
    likovi.DodajKvadrat("Plavi",5); kVADRAT <- PRAVOUGAONIKA,PRAVOUGAONIK <- APSTRAKTNI LIK, APSTRAKTNI LIK <- KOLEKCIJA LIKOVA
    likovi.IspisiKolekciju();

*/
    PolimorfniLik lik1,lik2;
    Krug k("Crna",4); Pravougaonik p("plava",2,3); Trougao t ("crvena",3,4,5);
    lik1 = k;
    lik1.Ispisi();
    lik2 = p;
    lik2.Ispisi();
    lik2 = lik1;
    lik1 = t;
    lik2.Ispisi();
    lik1.Ispisi();
    PolimorfniLik lik3(Kvadrat("Zelena",2));
    lik3.Ispisi();

    return 0;
}
