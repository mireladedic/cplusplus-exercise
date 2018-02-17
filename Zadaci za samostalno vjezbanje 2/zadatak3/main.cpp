#include <iostream>
#include <vector>


bool funk ( int n ){
    bool jeste;

    std::vector<int>v;
    while(n != 0){
        int c = n % 10;
        v.push_back(c);
        n /= 10;
    }

    for(int i = 0; i < v.size(); i++)
        std::cout<<v[i]<< " | ";
    std::cout<<"\n";
    for(int i = 0 , j = v.size() - 1; i < v.size(),  j >= i; i++ , j--){
          std::cout<< i  << " : " << j  <<" - ";
          std::cout<<v[i]  << " : " << v[j] <<"\n";

        if(v[i] == v[j]) jeste = true;
        else {jeste = false; break;}

    }
   // std::cout<<"--" << jeste <<"\n";
    return jeste;
}
int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    std::cout<< (funk(n) ? "\nSimetrican!" : "\nNije simetrican!");

    return 0;
}
