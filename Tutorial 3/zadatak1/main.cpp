#include <iostream>
#include <vector>
bool prost(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    std::cout<<"Unesite n: " << std::endl;
    int n;
    std::cin >> n;

    std::cout<<"Unesite brojeve: \n";
    std::vector<int>a;
    for(int i = 0; i < n;i++){
        int br;
        std::cin >> br;
        a.push_back(br);
    }

    std::vector<int>b;
    std::vector<int>c;

    for(int i = 0; i < a.size(); i++){
      if(a[i] == 1) continue;
        if(prost(a[i])) b.push_back(a[i]);
        else {  c.push_back(a[i]);  }
    }

    std::cout<<"Prosti: \n";
    for(int i = 0; i < b.size();i++){
        if(i == b.size() - 1) std::cout<<b[i];
        else std::cout<<b[i] << ",";
    }


    std::cout<<"\nSlozeni: \n";
    for(int i = 0; i< c.size(); i++){
        if(i = c.size() - 1) std::cout<<c[i];
        else std::cout<<c[i] << ",";

    }
    return 0;
}
