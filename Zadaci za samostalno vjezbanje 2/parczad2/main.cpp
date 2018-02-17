#include <iostream>
#include <vector>
/* SUM PRVIH N ELEMENATA
int pomocna(int n){
    int sum = {0};

    for(int i = 1; i <=(n/2); i++){
            sum += i;
            std::cout<<i << j <<" | " << sum << std::endl;
            if(n == sum) break;
        }
return sum;
}
*/

int pomocna(int n){
    int sum = {0};
    int br;
    for(int i = 1; i <=(n/2); i++){
        sum=0;

        for(int j=i; j<i + 5; j++)
        {
            sum += j;
            if(n == sum && j==i+4) {
               return sum;
            }

        }


    }

}

std::vector<int> funkcija(std::vector<int>v){
    std::vector<int> vektor;
    for(int i = 0; i< v.size(); i++){
        if(v[i] == pomocna(v[i])){ vektor.push_back(v[i]); }
    }
return vektor;
}

int main()
{
    std::cout<<"Unesite n: "<<std::endl;
    int n;
    std::cin >> n;

    std::cout<<"Unesite brojeve u vektor: "<<std::endl;
    std::vector<int>v;
    for(int i = 0; i < n; i++){
        int br;
        std::cin>>br;
        v.push_back(br);
    }


    std::vector<int>vektor;
    vektor = funkcija(v);

    std::cout<<"Elementi novog vektora: "<<std::endl;
    for(int i = 0; i < vektor.size(); i++)
    {
        std::cout<< vektor[i] << " ";
    }

    return 0;
}
