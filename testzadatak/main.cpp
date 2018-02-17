#include <iostream>
#include <stdexcept>
#include <cstring>
class Datum{
    int dan,mjesec,godina;
public:
Datum(int dan, int mjesec, int godina);
void Postavi(int dan, int mjesec, int godina);

int DajDan() const;
int DajMjesec() const;
int DajGodinu() const;
void Ispisi() const;
};

Datum::Datum(int dan,int mjesec,int godina){
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Datum::Postavi(int dan,int mjesec,int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina% 4 == 0 && (godina % 100 != 0 || godina %400 == 0))
        broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec -1])
        throw std::domain_error("Neispravan datum.\n");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
int Datum::DajDan() const {    return Datum::dan; }
int Datum::DajMjesec() const { return Datum::mjesec ;}
int Datum::DajGodinu() const { return Datum::godina; }
void Datum::Ispisi()const{
    std::cout<<Datum::dan <<"/"<<Datum::mjesec<<"/"<<Datum::godina;
}

class Kupac{

    std::string ime_i_prezime;
    Datum datum_rodjenja;

static bool ispravno(const std::string s){
    bool pravilno = false;
    for(int i = 0; i < s.length();i++){
        pravilno =(s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i]<='z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == ' ' || s[i] == '"' || s[i] == '\n' || s[i] == '\0';
    }
  return pravilno;
}

public:
Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);

std::string DajImePrezime() const;
Datum DajDatumRodjenja() const;
void Ispisi() const;
};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime_i_prezime (ime_i_prezime), datum_rodjenja(datum_rodjenja){
    //if(!ispravno(ime_i_prezime)) throw std::domain_error("Neispravno Ime_i_Prezime.\n");
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    Kupac::ime_i_prezime =(ime_i_prezime);
    Kupac::datum_rodjenja =(datum_rodjenja);
    //if(!ispravno(ime_i_prezime)) throw std::domain_error("Neispravno Ime_i_Prezime.\n");
}

inline std::string Kupac::DajImePrezime() const { return Kupac::ime_i_prezime; }
inline Datum Kupac::DajDatumRodjenja() const { return Kupac::datum_rodjenja;}

inline void Kupac::Ispisi() const{
    std::cout<<Kupac::ime_i_prezime<<"(";
     datum_rodjenja.Ispisi();
    std::cout<<")."<<std::endl;
}

class Stan{
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten = false;
    double kvadratura;
public:
Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura);
void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);

std::string DajAdresu() const;
int DajSprat() const;
int DajBrojSoba() const;
bool DajNamjesten() const;
double DajKvadraturu() const;
void Ispisi() const;
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
        if(sprat < 1 || broj_soba < 1 || kvadratura < 1) throw std::domain_error("Neispravan parametar.\n");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
        if(sprat < 1 || broj_soba < 1 || kvadratura < 1) throw std::domain_error("Neispravan parametar.\n");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;


}
std::string Stan::DajAdresu() const{ return Stan::adresa; }
int Stan::DajSprat() const{ return Stan::sprat; }
int Stan::DajBrojSoba() const {  return Stan::broj_soba; }
bool Stan::DajNamjesten() const{ return Stan::namjesten; }
double Stan::DajKvadraturu() const{ return Stan::kvadratura; }

void Stan::Ispisi() const{
    std::cout<<"Stan se nalazi na adresi "<< Stan::adresa <<"na " << Stan::sprat << " spratu i ima "<<Stan::broj_soba<<" soba.\n";
    std::cout<<"Kvadratura stana je "<< Stan::kvadratura<< " i stan ";
    if(Stan::namjesten) std::cout<<"je namjesten.\n";
    else std::cout<<"nije namjesten.\n";
}

class Prodaja{
   std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana= Kupac("", Datum(0,0,0));
    Stan kupljeni_stan =  Stan("", 0, 0, false, 0);

public:
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca,
        const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata);

void PromijeniKupca(const Kupac &novi_kupac);
void PromijeniStan(const Stan &novi_stan);
void PromijeniDatumKupovine(const Datum &novi_datum);
void PromijeniCijenuProdaje(const double &nova_cijena);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();

std::string DajImeAgenta() const;
std::string DajImeKupca() const;
Datum DajDatumProdaje() const;
double DajCijenuStana() const;

friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);

void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):
cijena_stana(cijena_stana),datum_prodaje(datum_prodaje)
{
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::kupac_stana = Kupac(kupac_stana);
    Prodaja::kupljeni_stan = Stan(kupljeni_stan);

}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata) :
cijena_stana (cijena_stana),datum_prodaje (dan_prodaje,mjesec_prodaje,godina_prodaje)
{
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::kupac_stana = Kupac(ime_kupca,datum_rodjenja_kupca);
    Prodaja::kupljeni_stan = Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
}

std::string Prodaja::DajImeAgenta() const{ return Prodaja::ime_agenta_prodaje;}

std::string Prodaja::DajImeKupca() const{
  return  Prodaja::kupac_stana.DajImePrezime();
}

Datum Prodaja::DajDatumProdaje() const{ return Prodaja::datum_prodaje;}
double Prodaja::DajCijenuStana() const{return Prodaja::cijena_stana;}

void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
    Prodaja::kupac_stana = novi_kupac;
}
void Prodaja::PromijeniStan(const Stan &novi_stan){
    Prodaja::kupljeni_stan = novi_stan;
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    Prodaja::datum_prodaje = novi_datum;
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    Prodaja::cijena_stana = nova_cijena;
}

/*...KAKO IZ JEDNE KLASE PRISTUPITI OBJEKTIMA DRUGE KLASE ...
void Prodaja::PomjeriDanUnaprijed(){

 /* Datum dat = Datum(Prodaja::datum_prodaje.DajDan(),Prodaja::datum_prodaje.DajMjesec(), Prodaja::datum_prodaje.DajGodinu());
  int br_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
  dat.DajDan()++;
  if(dat.DajDan() > br_dana[dat.DajMjesec() - 1]) dat.DajDan() = 1,dat.DajMjesec()++;
  if(dat.DajMjesec() > 12) dat.DajMjesec() = 1, dat.DajGodinu()++;
  int dan = datum_prodaje.DajDan(), mjesec = datum_prodaje.DajMjesec(),godina = datum_prodaje.DajGodinu();
    dan++;
    datum_prodaje = Datum(dan,mjesec,godina);

}

void Prodaja::PomjeriDanUnazad(){
    int dan = datum_prodaje.DajDan(), mjesec = datum_prodaje.DajMjesec(),godina = datum_prodaje.DajGodinu();
    dan--;

    datum_prodaje = Datum(dan,mjesec,godina);
}
*/

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    bool prodat = false;
    if((p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu())
    || (p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec())
    || (p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan())
    ) prodat = true;
    return prodat;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    bool skuplji = false;
    if(p1.DajCijenuStana() > p2.DajCijenuStana()) skuplji= true;

    return skuplji;
}

void Prodaja::Ispisi() const{
    std::cout<<"Ime agenta:"<<Prodaja::ime_agenta_prodaje<<std::endl;
    std::cout<<"Ime kupca:" ;    kupac_stana.Ispisi();
    std::cout<<"Zakazani datum prodaje:";   datum_prodaje.Ispisi();
    std::cout<<"Informacije o stanu:\n";    kupljeni_stan.Ispisi();
}
/*
class Prodaje {
    int max_broj_prodaja;
    int broj_evidentiranih_prodaja;
    Prodaja **prodaje;

public:
explicit Prodaje(int max_broj_prodaja): max_broj_prodaja(max_broj_prodaja),broj_evidentiranih_prodaja(0),prodaje = new Prodaja*[max_broj_prodaja]{}
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);

~Prodaje(){ for(int i = 0; i < broj_evidentiranih_prodaja;i++) delete prodaje[i]; delete[] prodaje;}

Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje);

Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje);

void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
void RegistrirajProdaju(Prodaja *prodaja);

Prodaja &DajProdaju(int redni_broj_prodaje); // ukoliko redni broj prodaje < 0 throw izuzetak
int DajBrojProdaja() const;
int DajBrojProdajaNaDatum(const Datum &datum) const;
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;

Prodaja &DajNajranijuProdaju();
Prodaja DajNajranijuProdaju() const;

Prodaja &DajNajskupljuProdaju();
Prodaja DajNajskupljuProdaju() const;

void IsprazniKolekciju();
void ObrisiNajranijuProdaju();
void ObrisiProdajeAgenta(const std::string &ime_agenta);
void ObrisiProdajeNaDatum(const Datum &datum);

void IspisiProdajeNaDatum(const Datum &datum) const;
void IspisiSveProdaje() const;
// u glavnom programu ograniciti makismalan broj prodaja na 20
};
*/
int main()
{
    Datum dat(04,02,1996);
    std::cout<<"dan "<< dat.DajDan()<<std::endl;
    std::cout<<"mjesec "<<dat.DajMjesec()<<std::endl;
    std::cout<<"godina "<<dat.DajGodinu()<<std::endl;
    dat.Ispisi();

    Kupac kupac("Mirela Dedic", dat);
    dat.Postavi(01,10,1994);
    kupac.Postavi("Ajla Topuz",dat);
    std::cout<<std::endl;
    std::cout<<"ime_i_prezime "<< kupac.DajImePrezime()<<"\ndatum ";
    Datum a = kupac.DajDatumRodjenja();
    a.Ispisi();
    std::cout<<std::endl;

    kupac.Ispisi();

    Stan stancic("Ibrahima Ljubovica 45", 2,3,true,90);
    std::cout<<"adresa: "<< stancic.DajAdresu()<<std::endl;
    std::cout<<"sprat: "<< stancic.DajSprat()<<std::endl;
    std::cout<<"broj soba : "<< stancic.DajBrojSoba()<<std::endl;
    std::cout<<"namjesten : "<< stancic.DajNamjesten()<<std::endl;
    std::cout<<"kvadrata : "<< stancic.DajKvadraturu()<<std::endl;

    stancic.Ispisi();

 /*   Prodaja prodaj("Ajla Topuz",150000, 29,05,2017,(std::string &) "Mirela Dedic",dat,"Ibrahima Ljubovica 45",2,3,true,90);
    Datum datum(29,05,2017);
    Prodaja prodat("Ajla Topuz",150000,datum,kupac,stancic); */
    return 0;
}
