#include <iostream>
#include <vector>
#include<initializer_list>
#include<algorithm>
/*....ZADATAK4
Napišite generičku klasu "Skup" koja oponaša najosnovnije funkcionalnosti bibliotečnog tipa "set"
putem svog jedinog privatnog atributa koji je tipa "vector".
Potrebno je podržati konstruktor bez parametara koji kreira prazan "Skup",
te sekvencijalni konstruktor koji prihvata inicijalizacionu listu i na osnovu nje popunjava atribut-vektor u sortiranom poretku,
uz izostavljanje duplikata. Od metoda treba podržati metodu "Velicina" koja vraća broj elemenata "Skup"-a,
zatim "Dodaj" koja u "Skup" dodaje novi element proslijeđen kao parametar,
vodeći računa da elementi ostanu sortirani,
te metodu "Izbrisi" koja uklanja element proslijeđen kao parametar (vektor treba ostati sortiran).
U slučaju da element već postoji u "Skup"-u, metoda "Dodaj" ne treba uraditi ništa,
 što je u skladu sa ponašanjem metode "insert" tipa "set". Isto vrijedi i za metodu "Izbrisi" u slučaju da element nije pronađen.
Konačno, treba implementirati i metodu "ImaLiGa" koja testira da li se element zadan kao parametar nalazi u "Skup"-u ili ne (
ona vraća odgovarajuću logičku vrijednost kao rezultat), te metodu "Ispisi" koja ispisuje sve elemente "Skup"-a na ekran (naravno, u sortiranom poretku).
*/

template<typename Tip>
class Skup{
    std::vector<Tip>elementi;
public:
    Skup() = default;
    Skup(std::initializer_list<Tip> lista);
    int Velicina()const{ return elementi.size();}
    void Dodaj(const Tip &element) ;
    void Izbrisi(const Tip &element)  ;
    bool ImaLiGa(const Tip &element)const;
    void Ispisi()const;
};
template<typename Tip>
Skup<Tip>::Skup(std::initializer_list<Tip> lista){
    for(auto x : lista) Dodaj(x);
}

template<typename Tip>
/*
void Skup<Tip>::Dodaj(const Tip &element) {
    if(ImaLiGa(element)) return;
    elementi.push_back(element);
    std::sort(elementi.begin(),elementi.end());
}
*/

void Skup<Tip>::Dodaj(const Tip &element){
    //..ovo zahtjeva da je vektor prethodno bio sortiran
    auto it (elementi.begin());
    while(it != elementi.end() && *it < element) it++; // PROLAZI KROZ VEKTOR I UKOLKO JE TRENUTNI ELEMENT VECI OD BILO KOJEG DRUGOG POMJERAJ ITERATOR DOK NE DODJES DO MJESTA GDJE TREBA UBACITI TAJ ELEMENT
    if(it == elementi.end() || *it != element) elementi.insert(it,element); // UKOLIKO SI PROSAO KROZ VEKTOR I VIDIO DA NEMA TOG ELEMENTA ONDA GA DODAJ NA KRAJ
}

template<typename Tip>
void Skup<Tip>::Izbrisi(const Tip &element){
    auto it ( std::find(elementi.begin(),elementi.end(),element));
    if(it != elementi.end()){
        elementi.erase(it);
    }
}

template<typename Tip>
bool Skup<Tip>::ImaLiGa(const Tip &element)const {
    return std::binary_search(elementi.begin(),elementi.end(),element);
}

template<typename Tip>
void Skup<Tip>::Ispisi()const{
    for(auto x : elementi) std::cout<<x<<" | ";
}
int main()
{
    Skup <int>s;
    s.Ispisi();
    Skup <int>skup({1,2,3,4,5});
    skup.Ispisi();
    std::cout<<"\n"<<skup.Velicina()<<std::endl;
    skup.Dodaj(6);
    skup.Ispisi();
    skup.Izbrisi(3);
    std::cout<<"\n";
    skup.Ispisi();
    std::cout<<"\n"<<std::boolalpha<<skup.ImaLiGa(8);


    return 0;
}
