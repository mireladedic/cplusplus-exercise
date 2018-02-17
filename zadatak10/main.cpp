#include <iostream>
#include <utility>
#include<string>
template <typename Tip1,typename Tip2>
    struct UredjenPar{
        Tip1 prvi;
        Tip2 drugi;
    };
template<typename Tip1,typename Tip2>
UredjenPar<Tip1,Tip2> NapraviPar(Tip1 prvi,Tip2 drugi){
        UredjenPar<Tip1,Tip2>novi_par;
        novi_par.prvi = prvi;
        novi_par.drugi = drugi;
        return novi_par;
}
int main()
{

    UredjenPar<double, double> par = NapraviPar<double,double>(1,2);
    std::cout<<par.prvi<<"|"<<par.drugi;

    /*UredjenPar<double, double> par;
    par.prvi = 1;
    par.drugi = 2;

    std::cout<<par.prvi<<"|"<<par.drugi<<std::endl;

    std::pair<double,double>tacka_u_ravni,par_brojeva;
    std::pair<std::string,int>osoba_i_broj;

    tacka_u_ravni.first = 1;
    tacka_u_ravni.second = 2;

    par_brojeva.first = 88;
    par_brojeva.second = 99;

    osoba_i_broj.first = "Mirela";
    osoba_i_broj.second = 17082;

    std::cout<<tacka_u_ravni.first <<" | "<<tacka_u_ravni.second<<std::endl;
    std::cout<<par_brojeva.first <<" | "<<par_brojeva.second<<std::endl;
    std::cout<<osoba_i_broj.first <<" | "<<osoba_i_broj.second<<std::endl;

    tacka_u_ravni = std::make_pair(12,13);
    std::cout<<tacka_u_ravni.first <<" | "<<tacka_u_ravni.second<<std::endl;
    */
    return 0;
}
