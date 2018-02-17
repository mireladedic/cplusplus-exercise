/* TP, 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <type_traits>
#include <functional>



//...SUMA CIFARA TESTNA FUNKCIJAi
     int  SumaCifara( int n){
         int suma (0);
        while(n != 0){
            suma += n % 10;
            n /= 10;
        }

        return suma;
    }

//... POTREBNE FUNKCIJE ZA TESTIRANJE ....
int SumaDjelilaca (long long int n){
	 int  suma (0);
	for(int i = 1; i <= n; i++){
		if(n % i == 0) {
		//	std::cout<<"| "<<i;
			suma += i;
		}
	}

	return suma;
}
int BrojProstihFaktora(long long int n){
	int br(0);
	//...UKOLIKO JE DJELJIV SA 2

	while(n % 2 == 0){
		std::cout<<2<<" ";
		br++;
		n /= 2;
	}

	//...UKOLIKO JE DJELJIV SA 3,5,7,9....NEPARNI
    int ostatak;
	for(int i = 3; i < n ;i= i + 2){

		while(n % i == 0){
			std::cout<<i<<" ";
			n /= i;
			br++;
		}
        ostatak = n;
	}

	//... ONO STO JE OSTALO...

	if(ostatak > 2){
	std::cout<<n<<" ";
	br++;
	}

	return br;
}

bool SavrsenBroj(long long int n){
	int suma (0);

	int i = 1;
	while(n % i == 0){
		suma+= i;
		i++;
	}
	if(suma == n) return true;
	return false;
}


template<typename IterTip,typename T,typename Tip>

auto UvrnutiPresjek(IterTip p1,IterTip p2,T p3,T p4, Tip f) -> typename std::remove_reference<decltype(*p1)**>::type{

    typedef std::pair<IterTip,T>par;
    std::vector<par> s;


    int n (0);
    while(p1 != p2){
    if( f(*p1) == f(*p3) ){
        //...BROJI KOLIKO IH IMA KOJI ZADOVOLJAVAJU USLOV
        s.push_back(std::make_pair( *p1,*p3 ));

        n++;
    }
  }

  for(int i (0); i < s.size(); i++){
    std::cout<<s[i]<<" : ";
  }
    //....KREIRA MATRICU FORMATA N X 3
    std::vector<std::vector<int>> m;
    for(int i (0); i <n; i++){
        for(int j(0); j < 3; j++){
            m[i][j] = s[i];
            std::cout<<m[i][j]<<" | ";
        }
    }
    return m;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera:\n";
	int n;
	std::cin>> n;
/*
int br = BrojProstihFaktora(n);
std::cout<<"\n Broj = "<< br;
*/
    std::cout<<"Unesite elemente prvog kontejnera:";
    std::deque<int> d1;

    for(int i = 0; i < n; i++){
        int br;
        std::cin >> br;

        /*...IZBACUJE SAMO AKO SU JEDAN DO DRUGOG
        if(i - 1 >= 0 && d1[i - 1] == br ) continue;
        */

        d1.push_back(br);
    }

    std::cout<<"\nUnesite broj elemenata drugog kontejnera: ";
    int m;
    std::cin>> m;

    std::cout<<"\nUnesite elemente drugog kontejnera:";
   std::deque<int> d2;

   for(int i = 0; i < m; i++){
    int br;
    std::cin>> br;

    d2.push_back(br);
   }

    std::cout<<"\nUvrnuti presjek kontejnera:\n";
    std::vector<std::vector<int>> UP;
    std::function<int(int)> x = SumaCifara;
       UP = UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(), //int *SumaCifara(*int)
                            SumaCifara);
//.. d1.begin() je pokazivac ili iterator na element deka
    std::cout<<"\nUvrnuta razlika kontejnera:\n";

	return 0;
}
