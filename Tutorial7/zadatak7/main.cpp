#include <iostream>
#include <deque>
#include<string>
#include <algorithm>

int main()
{
    std::deque<std::string> d;
    std::string s;
    for(int i=0; i<3; i++)
    {std::getline(std::cin,s);
    d.push_back(s);
    }
    std::deque<std::string> d1(3);
    std::copy_if(d.begin(),d.end(),d1.begin(),
                 [](std::string s)->bool
                 {
                     int br=0;
                     for(int i=0; i<s.size(); i++)
                        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') br++;
                     return br>5;
                 }
                 );
    for(int i=0; i<d1.size(); i++)
    {
        for(int j=0; j<d1[i].size(); j++)
        {
            std::cout<<d1[i][j];
        }
        std::cout<<std::endl;
    }
        return 0;
        }

