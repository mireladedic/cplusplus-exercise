#include <iostream>
#include <vector>
#include <stdexcept>
// NE RADI..
std::vector<bool> sumauzast(std::vector<int> &v){
    std::vector<bool>b;
    bool temp = 0;
    for(int i (0); i < v.size();i++){
        if(v[i] < 0) throw std::domain_error("Negativan broj!\n");

        for(int j (1); j < v[i]; j++){
            if(v[i] == j + (j + 1) + (j + 2) + (j + 3) + (j + 4)){
                b.push_back(1);
                temp = 1;
            }
        }

    }


    return b;

}

int main()
{
    std::vector<int>v {20,14};
    try{
        std::vector<bool> b = sumauzast(v);
        for(int i (0); i < b.size(); i++){
            std::cout<<std::boolalpha<<b[i]<<" | ";
        }
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
