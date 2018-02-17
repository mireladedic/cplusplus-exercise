#include <iostream>
#include <vector>

int period (std::vector<double>v){

    int zadnji = 0;
    int duzina = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){



            if(v[i] == v[j]) {
                std::cout<<v[i]<<" ";
                zadnji = v[i];
                //if(j > i) return j - i;
            }
        else {

        }

    }
    }
int main()
{
    std::cout<<"Unesite vektor brojeva: " << std::endl;
    std::vector<double> v;

    double br;

    while(std::cin >> br){
        if(br == 0) break;
        v.push_back(br);
}

        std::cout<<"duzina perioda: " << period(v) << std::endl;
    return 0;
}
