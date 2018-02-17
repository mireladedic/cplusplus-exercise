#include <iostream>
#include <cmath>
class Vector3d{
    /*... PPRIVATE: DEFINIRAJU SE SVI ATRIBUTI KLASE, I NEKE FUNKCIJE KOJE SU POTREBNE FUNKCIJAMA CLANICAMA TE KLASE
    PRIVATNIM ATRIUTIMA SE MOZE PRISTUPITI SAMO IZ FUNKCIJA CLANICA TE KLASE. ATRIBUTI OZNACENI SA MUTABLE SE MOGU MIJENJATI CAK IZ
    FUNKCIJA CLANICA KOJE SU OZNACENE KAO KONSTANTE */
    double x,y,z;
    /*...DEFINIRAJU SE SVE FUNKCIJE CLANICE TE KLASE (NAVODECI NJIHOVE PROTOTIPOVE I EVENTUALNE IMPLEMENTACIJE, I METODE TE KLASE
        FUNKCIJE CLANICE SE PRIMJENJUJU NAD KONKRETNIM OBJEKTOM TE KLASE POMOCU OPERATORA . , SVAKA FUNKCIJA CLANICA U SEBI SADRZI INDENTIFIKATOR
        THIS KOJI UKAZUJE NA BAS TAJ JEDAN OBJEKAT TE KLASE. NEKA FUNKCIJA CLANICA SE MOZE PROGLASITI ZA INLINE,TJ. UMETNUTA, IAKO SE DEFINIRA IZVAN KLASE
        , TO SLUZI KAO PREPORUKA KOMPAJLERU DA NA MJESTO PROTOTIPA UMETNE NJENU IMPLEMENTACIJU. "KRATKE" FUNKCIJE SE IMPLEMENTIRAJU ODMAH KOD
        DEKLARACIJE PRI CEMU DOBIJAMO NA BRZINI.FUNKCIJE KOJE NE MIJENJAJU VRIJEDNOST ATRIBUTA NAZIVAJU SE INSPEKTORI,DOK ONE KOJE MIJENJAJU SU MUTATORI.
        INSPEKTORE OZNACAVAMO SA CONST,NA TAJ NACIN OMOGUCAVAMO PRIJAVU GRESKE U SLUCAJU PROMJENE ATRIBUTA KLASE,I NA TAJ NACIN JE MOGUCE OSTVARITI DA
        KONSTANTNI OBJEKTI BUDU POZVANI NAD TIM FUNKCIJAMA. PA KLASA MOZE IMATI I KONSTANTNE I NEKONSTANTNE INSPEKTORE. PRI CEMU SE JEDNI POZIVAJU NAD OBICNIM
        A DRUGI NAD KONSTANTNIM OBJEKTIMA.
        AKO STAVIMO & ISPRED NAZIVA FUNKCIJE,OMOGUCAVAMO NADOVEZIVANJE NPR. V1.SABERISA.POMNOZISA(V2).OZNACIMO LI OBICNU FUNKCIJU SA FRIEND,DAJEMO
        JOJ SVA PRAVA PRISTUPA PRIVATNOM DIJELU KLASE,TJ. SVIM ATRIBUTIMA.FUNCKIJE CLANICE MOZEMO PROGLASITI STATICKIM, PRI CEMU ONE DOBIJAJU ISTI SMISAO
        KAO I FRIEND OBICNE FUNCKIJE
    */
    public:
    void Postavi(double x,double y,double z){
        Vector3d::x = x;
        this->y = y;
        Vector3d::z = z;
    }

    void Ocitaj(double x,double y,double z){
        x = Vector3d::x;
        y = Vector3d::y;
        z = Vector3d::z;
    }

    void Ispisi() const{
        std::cout<<"{ "<< x << " , " << y << " , "<<z << "} "<<std::endl;
    }

    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }

    double DajDuzinu()const { return std::sqrt( x * x + y * y + z * z);}

    Vector3d &SaberiSa(const Vector3d &v){
        x += v.x;    y += v.y ;     z += v.z;
        return *this;
    }

    Vector3d &PomnoziSaSkalarom(double s){
        x *= s; y *= s; z *= s;
        return *this;
    }

   friend ZbirVektora(const Vector3d &v1, const Vector3d &v2);

};

friend Vector3d ZbirVektora(const Vector3d &v1,const Vector3d &v2){
    Vector3d v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;

    return v3;
  }


int main()
{
    Vector3d vektor;
    std::cout<<"Unesi:\n";
    double x,y,z;
    std::cin>> x >> y >> z;
    vektor.Postavi(x,y,z);
    std::cout<<vektor.DajX() << "|" << vektor.DajY() << "|" << vektor.DajZ()<<std::endl;
    return 0;
}
