#include <iostream>
#include <vector>
#include <stdio.h>

int pomocna(int n){

    int min=n%10;
    n=n/10;
    int temp;

    while(n != 0){

        temp=n%10;
        if(temp < min) min = temp;
        n=n/10;
    }
    return min;

}


std::vector<int>funkcija(std::vector<int>v){
    std::vector<int>vektor;
    for(int i = 0; i< v.size(); i++){

       vektor.push_back(pomocna(v[i]));


    }
    return vektor;

}

int main()
{
    std::cout<<"Unesite n: "<< std::endl;



    std::vector<int> v;
    for(int i = 0; i < 100; i++){
        int br;
        std::cin>>br;
        v.push_back(br);
        if(br==0) break;
    }
    std::vector<int> x;
     x =  funkcija(v);


    for(int i = 0; i < x.size(); i++){
        std::cout<<x[i] << " ";
    }



    return 0;
}
