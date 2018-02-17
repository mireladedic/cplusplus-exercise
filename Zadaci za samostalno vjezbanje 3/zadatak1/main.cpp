#include <iostream>
#include <vector>

int pomocna(int n){
     int br = n;
        int sum{0};
        while (br != 0) {
            int c = br % 10;
            sum += c;
            br/= 10;

        }
    return sum;
}
std::vector<int> funkcija(int n){
    std::vector<int> v;
    for(int i = 1; i <= n; i++) {
     if(  i > 10 && i % pomocna(i) == 0) {
        std::cout<<i<< " ";
        v.push_back(i);
     }
    }

    return v;
}
int main() {
    std::cout << "Unesite n: " << std::endl;
    int n;
    std:: cin >> n;

    std::vector<int>v = funkcija(n);
    std::cout<<"\n";
        for(int i = 0; i < v.size(); i++)
            std::cout<<v[i]<<" | ";

    return 0;
}
