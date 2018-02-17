#include <iostream>
#include <set>
#include<vector>
#include <initializer_list>

template<typename Tip>
class Skup{
    std::vector<Tip>elementi;
public:
    Skup(std::initializer_list<Tip>lista) : (elementi.size())(lista.size()){
        std::copy(lista.begin(),lista.end(),elementi.begin());
    }
};

int main()
{
    std::set<int> s1{3, 5, 1, 2, 8}, s2{7, 2, 8, 4};
    std::cout << s1 + s2 << std::endl;        // Ispis {1,2,3,4,5,7,8}
    std::cout << s1 * s2 << std::endl;        // Ispis {2,8}
}
