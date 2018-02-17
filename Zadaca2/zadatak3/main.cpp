#include <iostream>
#include <vector>
#include <stdexcept>
enum class Polje {
    Prazno,Prosjecno,Mina,BlokiranoPrazno,BlokiranoProsjecno,BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

/*... IMPLEMENTIRATI OVE FUNKCIJE............
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

*/

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
    Tabla t = {};
    //t.reserve(n);

    for(int i (0); i < mine.size(); i++){
        for(int j(0) ; j < mine[i].size();j++){
            if( mine[i].size() < 2) throw std::domain_error("Ilegalan format zadavanja mina!\n");

        }
    }

//...KREIRA TABLU VELICINE N I SVA POLJA POSTAVLJA NA PRAZNO
    //... PRVO NAPRAVI ....
    for(int i (0); i < n; i++){
        t.push_back(std::vector<Polje>());
        for(int j (0); j < n; j++){
            t[i].push_back(Polje(0));
            //t[i][j] = Polje(0);
        }
    }

    /*for(int i (0); i < n; i++){
        for(int j (0); j < n; j++){
            if(mine[i][j] > t.size ()|| mine[i][j] > t[i].size()) throw std::domain_error("Ilegalne pozicije mina!\n");
        }
    }*/

    /*... {0,0 0,2 1,2}
    for(int i (0); i < mine.size(); i++){
        for(int j (0); j < mine[i].size(); j++){
            std::cout<<mine[i][j]<<" ";
        }
    }
    */
    //....POSTAVLJA MINE NA ODGOVARAJUCU POZICIJU...

    for(int i (0); i < mine.size(); i++){

            if(mine[i][0] >= t.size()) throw std::domain_error("Ilegalne pozicije mina!\n");
            if(mine[i][1] >= t[mine[i][0]].size()) throw std::domain_error("Ilegalne pozicije mina!\n");
        t[mine[i][0]][mine[i][1]] = Polje(1);
    }

    for(int i (0); i < n; i++){
        for(int j (0); j < n; j++){
            std::cout<<int(t[i][j])<<" ";
        }
        std::cout<<std::endl;
    }

    return t;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
    //... NAPRAVI MATRICU 3X3
    std::vector<std::vector<int>>b = {{0,0,0}, {0,0,0}, {0,0,0}};


    int i=x, j=y;
    while(true) {
        if(i-1 >= 0) {
            if(j-1 >= 0 ) {
                for(int k(i-1), l(j-1); k<i+2; k++, l++) {
                    if()
                }
            }
        }
    }

    for(int i(0); i<polja.size(); i++) {
        for(int j(0); polja[i].size(); j++) {

            for(int k(0); k<9; k++) {

            }
        }
    }

}

int main()
{
    std::cout<<"test:\n";
    int n;
    std::cin >> n;
    const std::vector<std::vector<int>>mine { {0,0}, {0,2}, {1,3}};
    Tabla T = KreirajIgru(n, mine);


    return 0;
}
