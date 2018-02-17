#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

/* 4 slucaja osciliranja:

    * raste-opada-raste
    * opada-raste-opada
    * raste-raste-opada
    * opada-opada-raste

*/
bool funkcija (std::vector<int> v){

    /* PROVJERAVA SAMO PRVA 4 ELEMENTA !
      int br = 0,brojac = 0;
    for(int i = 0; i < v.size();i++){
     for(int j = 1; j < v.size(); j++){

        if(i == v.size()) break;

        if(v[i] < v[j]){
            br = 1;
            if(br = 1 && v[ i + 1] > v[j + 1])
                return true;
            }else if(v[i] > v[j]){
                brojac = 1;
                if(brojac = 1 && v[i + 1 ] < v[j + 1])
                    return true;
            }else{
                return false;
            }
     }
    }
    */
    /* PROVJERAVA CITAV VEKTOR */

    if(v.size() < 3) return false;
    int b = 0;
    for(int i(0), j(1), k(2); i < v.size(), j < v.size(), k < v.size(); i++, j++, k++) {

        //cout << v[i] << "," << v[j] << "," << v[k] << endl;

        // if(v[j] < v[i] && v[j] > v[k]) b++;
         if(v[j] > v[i] && v[j] > v[k]) b++;
            //r.push_back(v[j]);
        // else if(v[j] > v[i] && v[j] < v[k]) b++;
         else if(v[j] < v[i] && v[j] < v[k]) b++;
         else return false; // Ako nisu poslije prve iteracuje dobri,onda nije oscilatoran,i odmah vrati false;
            //r.push_back(v[j]);

        //else if(v[j] > v[i] && v[j] > v[k]) b++;
            //r.push_back(v[j]);
        //else if((v[j] < v[i] && v[j] < v[k])) b++;
            //r.push_back(v[j]);

    }

    return (b == v.size()-2);
}

int main()
{
    std::cout<<"Unesite n: \n";
    int n;
    std::cin >> n;


    std::cout<<"Unesite elemente: \n";
    std::vector<int>v;
    for(int i = 0 ; i < n; i++){
        int br;
        std::cin >> br;
        v.push_back(br);
    }

    std::cout<<"Vrijednos iz funkcije: \n";
    bool fu = funkcija(v);
    std::cout<<std::boolalpha<<fu;

    std::cout<< (funkcija(v) ? "\nOscilira!" : "\nNe oscilira!");

    return 0;
}
