#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
//...NE RADI....
std::string TriNaredbe(std::string s){
    std::string c;

    c = *(std::remove_copy(s.rbegin(),s.rend(),std::front_inserter (s), ' '));

    return c;
}

int main()
{

    std::string str {"Evo Pada Kisa"};
    std::string c = TriNaredbe(str);
    for(int i (0); i < c.size();i++){
        std::cout<<c[i];
    }
    return 0;
}
