#include <iostream>
#include <list>
#include <forward_list>
#include <set>
#include<unordered_set>
#include<stack>
#include<queue>

int main()
{
    /*
    std::list<int>lista{1,2,3};
    lista.push_back(4);
    lista.push_front(0);
    for(int x : lista) std::cout<<x<<" ";

    std::cout<<"\n";
    std::list<int>::iterator it(lista.begin());
    for(int i = 0; i < lista.size();i++){
        std::cout<<*it++<<"|";
    }
    std::cout<<std::endl;

    std::list<int>::iterator it1(lista.begin());
    while(it1 != lista.end())
        std::cout<<*it1++<<":";

      //++ != == --
      std::cout<<std::endl;
      std::list<int>l;
        for(;;){
                int x;
            std::cin >> x;
            if(x == 0) break;
            std::list<int>::iterator i(l.begin());
            while(i != l.end() && *i < x) i++;
            l.insert(i,x);
        }

        for(int x : l) {std::cout<<x<<"<";}


        for(auto iter = lista.begin();iter != lista.end();iter++)
        if(iter == lista.begin()) iter = lista.erase(iter);
        std::cout<<std::endl;
        for(auto x : lista) std::cout<<x<<" ! ";

        std::forward_list<int>jednosmjerna{10,11,12,13};
        insert_after()  UMETNI NA MJESTO KOJE SLIJEDI NAKON MJESTA NA KOJE POKAZUJE TRENUTNO ITERATOR
        erase_after() IZBRISI NA MJESTO KOJE SLIJEDI NAKON MJESTA NA KOJE POKAZUJE TRENUTNO ITERATOR
        before_begin() FIKTIVNO MJESTO KOJE PRETHODI PRVOM ELEMENTU LISTE VRACA ITERATOR

        std::cout<<std::endl;
        auto iteratorcic = jednosmjerna.before_begin();
        std::cout<<*iteratorcic<<" ";

        for(auto it3 = jednosmjerna.begin(); it3 != jednosmjerna.end(); it3++){
           // it3 = jednosmjerna.insert_after(it3,9);
           //    IZBRISE POSLIJE POCETKA I POSLIJE KRAJA
            if(it3 == jednosmjerna.begin() || it3 == jednosmjerna.end()) it3 = jednosmjerna.erase_after(it3);
        }
        std::cout<<std::endl;
        for(int x : jednosmjerna )std::cout<<x<<"|";
        */

        /*SVOJE ELEMENTE INTERNO CUVAJU U SORTIRANOM PORETKU
        std::set<int>skup{3,5,1,4,3,7};
        for(int x : skup ) std::cout<<x<<"|";
        std::cout<<std::endl;
        std::multiset<int>multiskup{3,5,1,4,3,7};
        for(int x : multiskup) std::cout<<x<<" ";
        std::cout<<std::endl;
        //SKUP NA POCETKU MOZE BITI PRAZAN,POCETNU VELICINU MU NE MOZEMO ZADATI
        skup.insert(9);
        multiskup.erase(3);
        for(int x : skup ) std::cout<<x<<"|";
        std::cout<<std::endl;
        for(int x : multiskup) std::cout<<x<<" ";
        std::cout<<std::endl;
        auto it= skup.find(9);
        std::cout<<*it<<std::endl;
        std::cout<<skup.count(9)<<std::endl;

        std::unordered_set<int>nesortiraniskup{1,5,9,7,8,12,45,79};
        std::unordered_multiset<int>nesortiranimultiskup{1,2,0,4,5,9,7,2};
        for(int x : nesortiraniskup ) std::cout<<x<<"|";
        std::cout<<std::endl;
        for(int x : nesortiranimultiskup) std::cout<<x<<" ";
        std::cout<<std::endl;
        */
      /*  STEK I RED NE PODRZAVAJU INDEKSIRANJE NI ITERATORE
        MOZE SE PRISTUPITI SAMO ELEMENTU KOJI JE NA VRHU KONTEJNERA
        stack     LIFO
        queue FIFO
        priority_queue BFO
        PUSH,POP,TOP,FRONT,BACK,SIZE,EMPTY,
        POP UKLANJA ELEMENT SA VRHA KONTEJNERA all
        TOP UZIMA ELEMENT SA VRHA KONTEJNERA stack i priority_queue
        PUSH DODAJE ELEMENT U KONTEJNER
        EMPTY VRACA TACNO AKO JE KONTEJNER PRAZAN
        front i back prvi i posljenji element u kontejneru queue
        */

        std::stack<int>stek;
        stek.push(1); stek.push(2);
        stek.push(3);
        while(!stek.empty()){
            std::cout<<stek.top()<<"|";
            stek.pop();
        }
        std::cout<<std::endl;
        std::queue<int>red;
        red.push(1); red.push(2); red.push(3);
        while(!red.empty()){
            std::cout<<red.front()<<"|";
            red.pop();
        }

        std::cout<<std::endl;
        std::priority_queue<int>redsaprioritetom;
        redsaprioritetom.push(1); redsaprioritetom.push(2); redsaprioritetom.push(3); redsaprioritetom.push(4);
        std::cout<<redsaprioritetom.size()<<std::endl;
         while(!redsaprioritetom.empty()){
            std::cout<<redsaprioritetom.top()<<"|";
            redsaprioritetom.pop();
        }


        std::cout<<"\n"<<red.back()<<std::endl;





    return 0;
}
