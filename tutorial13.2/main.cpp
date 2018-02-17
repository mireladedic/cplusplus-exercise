/*
    TP 16/17 (Tutorijal 13, Zadatak 4)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class ApstraktniStudent{
    std::string ime,prezime;
    int broj_indexa;
    int broj_polozenih_ispita;
    double prosjecna_ocjena;
public:
    ApstraktniStudent(std::string ime,std::string prezime,int index) : ime(ime),prezime(prezime),broj_indexa(index),broj_polozenih_ispita(0),prosjecna_ocjena(5.){}
    std::string DajIme() const {return ime;}
    std::string DajPrezime() const{ return prezime; }
    int DajIndex() const {return broj_indexa; }
    int DajPolozene() const { return broj_polozenih_ispita; }
    double DajProsjek() const{ return prosjecna_ocjena; }

    void RegistrirajIspit(int ocjena){
       if(ocjena == 5) return;

        broj_polozenih_ispita++;
        prosjecna_ocjena = double(ocjena / broj_polozenih_ispita);
    }

    /*void PonostiOcjene()const{
        ApstraktniStudent(std::string ime,std::string prezime,int index);
    };*/

    virtual ApstraktniStudent *DajKopiju()const = 0;
    virtual void IspisiPodatke() const = 0;

};




class StudentBachelor : public ApstraktniStudent{
public:
    StudentBachelor(std::string ime,std::string prezime,int index) : ApstraktniStudent(ime,prezime,index){}
    ApstraktniStudent *DajKopiju()const override {return new StudentBachelor(*this);};
    void IspisiPodatke() const override{
       std::cout<<"Student bachelor studija "<< DajIme() << " , " << DajPrezime()<<" sa brojem indeksa " << DajIndex() <<", ima prosjek " << DajProsjek()<<"."<<std::endl;
    }
};




class StudentMaster : public ApstraktniStudent{
    int bachelor_studij;
public:
    StudentMaster(std::string ime,std::string prezime,int index,int bachelor) : ApstraktniStudent(ime,prezime,index) , bachelor_studij(bachelor){}
    ApstraktniStudent *DajKopiju() const override {return new StudentMaster(*this);}
    void IspisiPodatke()const override{
        std::cout<<"Student master studija "<< DajIme()<<" , "<< DajPrezime() <<" sa brojem indeksa " << DajIndex()<<", zavrsio bachelor studij godine " << bachelor_studij<<" , ima prosjek " << DajProsjek()<<"."<<std::endl;
    }
};

class Fakultet {
    std::vector<ApstraktniStudent*>studenti;
public:
    // KONSTRUKTOR
    Fakultet() = default;

    // DESTRUKTOR
    ~Fakultet(){
        for(int i = 0; i < studenti.size(); i++) delete studenti[i];
    }


    Fakultet(const Fakultet &fakultet);
    Fakultet(Fakultet &&fakultet);
    //Fakultet(Fakultet fakultet);
    Fakultet &operator =(const Fakultet &fakultet) = default;
    Fakultet &operator = (Fakultet &&fakultet) = default;

    /*  POMJERAJUCI OPERATOR DODJELE
    Fakultet &operator = (Fakultet fakultet){
        std::swap(studenti,fakultet.studenti);
        return *this;
    }
    */
    void UpisiStudenta(std::string ime,std::string prezime,int index);
    void UpisiStudenta(std::string ime,std::string prezime,int index,int bachelor);
    void ObrisiStudenta(int index);

    ApstraktniStudent* operator[](int index){return studenti[index]; }
   	const ApstraktniStudent* operator[](int index) const{ return studenti[index];}

    void IspisiSveStudente()const{
        for(int i = 0; i < studenti.size();i++)
            (studenti[i])->IspisiPodatke();
    }
};
// KONSTRUKTOR KOPIJE
 Fakultet::Fakultet(const Fakultet &fakultet){

     try{
    for(int i = 0; i < fakultet.studenti.size(); i++)
        studenti.push_back((fakultet.studenti[i]) ->DajKopiju()));
    }catch(...){
        for(int i = 0; i < studenti.size();i++) delete studenti[i];
        throw;
    }


 }
 // POMJERAJUCI - POMJERI IZVORNI U ODREDISNI VEKTOR MOZE KORISTENJEM MOVE SEMANTIKE 0 TO RADI I AUTOMATSKI POMJERAJUCI KONSTRUKTOR
  Fakultet::Fakultet(Fakultet &&fakultet){
    studenti = fakultet.studenti;
    fakultet.studenti.resize(0);
  }

/* OPERATOR DODJELE
 Fakultet &Fakultet::operator =(const Fakultet &fakultet){
   for(int i = 0; i < studenti.size();i++) delete studenti[i]; studenti.resize(0);

     try{
        for(int i = 0; i < fakultet.studenti.size();i++) studenti.push_back((fakultet.studenti[i]->DajKopiju()));
    }catch(...){
        for(int i = 0; i < studenti.size();i++) delete studenti[i];  throw;
    }

    return *this;
 }

 POMJERAJUCI
  Fakultet &Fakultet::operator = (Fakultet &&fakultet){
    for(int i = 0; i < studenti.size();i++) delete studenti[i];

    studenti = fakultet.studenti;
    fakultet.studenti.resize(0);

    return *this;
  }
*/

void Fakultet::UpisiStudenta(std::string ime,std::string prezime,int index){

    studenti.push_back(new StudentBachelor(ime,prezime,index));

}
void Fakultet::UpisiStudenta(std::string ime,std::string prezime,int index,int bachelor){
    studenti.push_back(new StudentMaster(ime,prezime,index,bachelor));

}
/*void Fakultet::ObrisiStudenta( int index){
    for(int i = 0 ; i < studenti.size();i++){
        if(int((studenti[i])->DajIndex()) == index ) {
                delete studenti[i];
                studenti.resize(studenti.size() - 1);
    }
}
*/


//          SUROGARTSKA KLASA
class Student{
    ApstraktniStudent *student;
    // - KONSTRUKTOR SA JEDNIM PARAMETROM (DINAMICKI ALOCIRA KOPIJU OBJEKTA KOJEG OPONASA)
public:
    // MEOGU SE BEZBIJEDNO KOPIRATI,MEDJUSOBNO INICIJALIZIRATI
    Student() : student(nullptr){}
    ~Student() {delete student;}
    Student(const ApstraktniStudent &neki_student) : student(neki_student.DajKopiju()){} // INICIJALIZACIJA BILO KOJIM STUDENTOM

    //KONSTRUKTOR KOPIJE
    Student(const Student &novi){
        if(!novi.student) student = nullptr;
        else student = novi.student->DajKopiju();
    }

    //- POMJERAJUCI
    Student(Student && novi){
        student = novi.student;
        novi.student = nullptr;
    }
    //OPERATOR DODJELE
    Student &operator = (const Student &novi){
        ApstraktniStudent *prostor = nullptr;
        if(novi.student != nullptr) prostor = novi.student->DajKopiju();
        delete student;
        student = prostor;
        return *this;
    }

    //-POMJERAJUCI
    Student &operator = (Student &&novi){
        std::swap(student,novi.student);
        return *this;
    }

    void Ispisi()const{
        student->IspisiPodatke();
    }
};
int main()
{
    StudentBachelor SB((std::string)"Mirela",(std::string)"Dedic",17082);
    StudentMaster SM((std::string)"Ajna",(std::string)"Zatric",17171,2017);

    SB.IspisiPodatke();
    SM.IspisiPodatke();

    Fakultet f;
   	f.UpisiStudenta(std::string("Irfan"),std::string("Saric"),1245);
    f.IspisiSveStudente();

    return 0;
}
