#include <iostream>
#include <list>

template <typename Tip,typename tip>
tip PrekopirajSimetricno(Tip p1,Tip p2,tip p3){
    Tip p = p1;
    while(p1 != p2){
        *p3 = *p1;
        p1++;
        p3++;
    }

    p2--;
    while(p2 != p){
      *p3 = *p2;
      p2--;
      p3++;
    }
    *p3 = *p2;
    p3++;
    return p3;
}


int main()
{
    int n;
    std::cout<<"Unesite n:\n";
    std::cin>>n;

    std::list<int>lista;
    std::cout<<"Unesi elemente u listu: \n";
    for(int i = 0; i < n; i++){
        int br;
        std::cin >> br;
        lista.push_back(br);
    }

    std::list<int>l(6);

    auto it = PrekopirajSimetricno(lista.begin(),lista.end(),l.begin());

    //...ISPISI LISTU
    for(auto it1 = l.begin(); it1 != l.end(); it1++){
        std::cout<<*it1<<" | ";
    }
    return 0;
}
