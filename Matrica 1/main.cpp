//TP 2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template<typename TipElementa>
//....STRUKTURA....
struct Matrica {
    int br_redova,br_kolona;
    TipElementa ** elementi = nullptr;
};


template<typename TipElementa>
//...F1
void UnistiMatricu (Matrica <TipElementa> mat ){

    if(!mat.elementi) return;
    //...BRISI ONO NA STA POKAZUJE DVOSTRUKI POKAZIVAC
    for(int i (0); i < mat.br_redova; i++) delete[] mat.elementi[i];
    //....BRISI NIZ POKAZIVACA
    delete[] mat.elementi;
    //...POKAZIVAC STAVI NA NULL
    mat.elementi = nullptr;
}

template<typename TipElementa>
//....F2
Matrica<TipElementa> StvoriMatricu (int br_redova,int br_kolona ){

    Matrica<TipElementa>mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;

    mat.elementi = new TipElementa * [br_redova];
    for(int i (0); i < br_redova;i++) mat.elementi[i] = nullptr ;

    try{
        for(int i (0); i < br_redova;i++)
            mat.elementi[i] = new TipElementa [br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }


    return mat;
}

//...F3...
template<typename TipElementa>
void UnesiMatricu (char ime_matrice,Matrica<TipElementa> &mat){

    for(int i (0); i < mat.br_redova; i++){
        for(int j (0); j < mat.br_kolona; j++){

            std::cout<<ime_matrice << " (" << i + 1 << ","<< j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

//....F4
template<typename TipElementa>

void IspisiMatricu (const Matrica<TipElementa>&mat , int sirina_ispisa){

    for(int i (0); i < mat.br_redova;i++){
        for(int j (0); j < mat.br_redova;j++){
            std::cout<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
}

//...F5
template<typename TipElementa>

Matrica<TipElementa> ZbirMatrica (const Matrica<TipElementa> &m1, const Matrica <TipElementa> &m2){

    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije !");

    auto m3 (StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));

    for(int i (0); i < m1.br_redova; i++){
        for(int j (0); j < m1.br_kolona;j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[j][j];
        }
    }


    return m3;
}

//....f6
template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica <TipElementa> &m2){
    //...SAGLASNE ZA MNOZENJE
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje\n");
    //...PRODUKT MATRICA
auto m3 = StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona);

    for(int i (0); i < m1.br_redova; i++){
        for(int j (0); j < m2.br_kolona;j++){
              for(int k = i; k < m2.br_redova; k++){
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }

    return m3;
}
int main ()
{
    Matrica<double> a,b,c,produkt;
    int m , n;
    std::cout<<"Unesite broj redova i broj kolona za matrice:\n";
    std::cin >> m >> n;


    try{
        a = StvoriMatricu<double>(m,n);
        b = StvoriMatricu<double>(m,n);

        std::cout<<"Unesi matricu A:\n";
        UnesiMatricu('A',a);

        std::cout<<"Unesi matricu B:\n";
        UnesiMatricu('B',b);

        std::cout<<"Zbir ove dvije matrice je:\n";
        IspisiMatricu(c = ZbirMatrica(a,b), 7);

        std::cout<<"Produkt ove dvije matrice je:\n";
        IspisiMatricu(produkt = ProduktMatrica(a,b),7);

    }catch(std::bad_alloc){
        std::cout<<"Nedovoljno memorije!\n";
    }


    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c),UnistiMatricu(produkt);

    return 0;
}
