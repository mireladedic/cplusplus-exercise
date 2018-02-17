#include <iostream>
#include <vector>

    std::vector<int> NajduziMonotoniNiz(std::vector<int>v){
        std::vector<int>novi;

        int maks,makss;
        for(int i = 0,j = 1; i < v.size(), j < v.size(); i++,j++){
           // std::cout<< i << "  |  " << j<<std::endl;
        int duzina{0},brojac{0};
            if(v[i] <= v[j]) {
                   duzina++;

            }else{
                   brojac++;
            }



        }
           novi.push_back(1);
           return novi;
    }

int main()
{
  std::cout<<"Unesite brojeve: \n";
  int n;

  std::vector<int>v;
  while(std::cin>>n, n != 0){
        v.push_back(n);
  }

  std::vector<int>novi = NajduziMonotoniNiz(v);
/*
  for(int i = 0; i < novi.size();i++){
    std::cout<<novi[i]<< " | ";
  }
  */
    return 0;
}
