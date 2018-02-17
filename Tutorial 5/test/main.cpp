#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<string.h>

int PotencijalniKrivci(char **&a,std::vector<std::string>v){

	try{
		a =(new char*[v.size()])	;
		for(int i (0); i < v.size(); i++) a[i] = nullptr;

		try{
			for(int i (0); i < v.size(); i++){
				a[i] = new char [v[i].size()];
			}
		//.... 	DINAMICKI KREIRA NIZ POKAZIVACA NA DINAMICKI ALOCIRANE NIZOVE ZNAKOVA U KOJI CE SE SMJESTITI IMENA
	//	...PORSLIJEDJENA FUNKCIJI = U MATRICU PREPISATI SVA IMENA IZ VEKTORA

		for(int i (0); i < v.size(); i++ ){
			for(int j (0); j < v[i].size();j++){
				a[i][j]= v[i][j];
			}
		}

		/*...ispis...
		std::cout<<"Dinamicki alocirano:\n";
		for(int i (0); i < v.size();i++)
		{
		    std::cout<<a[i]<<" ";
			//for(int j(0); j < v[i].size();j++){
				//std::cout<<a[i][j]<<" ";
			//}
			std::cout<<"\n";
		}
		*/

		//...VRATI VELICINU NIZA POKAZIVACA..

		return v.size();

		//	return a; vrati u pok
		}catch(std::bad_alloc){
			for(int i (0); i < v[i].size(); i++) delete[] a[i];
			delete [] a;
		}
	}catch(...){
		std::cout<<"Nedovoljno memorije!\n";
	}
}
int OdbaciOptuzbu(char **&a,int vel,std::string s){
    int brojobrisanih {0};
	for(int i (0); i < vel; i++){

        //std::cout<< a[i] << " " << s.c_str() << std::endl;
        if(strcmp(a[i], s.c_str())== 0){
            //delete[] a[i];

            if(i+1 < vel) {
                if(a[i+1] != 0) {
                    a[i] = a[i+1];
                    delete[] a[i+1];
                    a[i+1] = nullptr;
                    brojobrisanih++;
                }
            }
            else {
                if(a[i] != 0) {
                delete[] a[i];
                a[i] = nullptr;
                brojobrisanih++;
                }
            }
        }
    }
/*
	for(int i(0); i < vel - brojobrisanih; i++){
        if(a[i] != nullptr) std::cout<<a[i]<<std::endl;
	}
	*/
	if(brojobrisanih == 0) {
        throw std::domain_error("Osoba sa imenom "+ s +" nije optuzena");
	}
/*
    for(int i (0); i < vel - brojobrisanih; i++){
        std::cout << a[i] << std::endl;
	}
*/
	 if(brojobrisanih > 10){
                //..OBAVI USTEDEU MEMORIJE...
                char **novi = new char *[vel - brojobrisanih];
                //... PREKOPIRA SE STARI NIZ POKAZIVACA U NOVI
               // if(a[i] != nullptr) novi[i] = a[i];
             novi = a;
            //... UKLONI STARI NIZ POKAZIVACA
            a = nullptr;
            a = novi;
    }
	return vel - brojobrisanih;

}

DodajOptuzbu();
//IzlistajOptuzbu();



int main ()
{
	std::cout<<"Unesite n:\n";
	int n;
	std::cin>>n;

	std::cout<<"Unesite vektor stringova:\n";
	std::vector<std::string>sp;
	std::string s;
	std::cin.ignore(10000,'\n');
	for(int i (0); i < n; i++){
		std::getline(std::cin,s);
		sp.push_back(s);
	}

	char**pk = nullptr;
	int vel = PotencijalniKrivci(pk,sp);
//	int novavel= OdbaciOptuzbu(pk,vel,s);
//	std::cout<<"| "<< vel<<std::endl;

    std::cout<<"Unesite string: \n";
    std::string c;
    std::getline(std::cin,c);
	int novavel = OdbaciOptuzbu(pk,vel,c);
	std::cout<<"| "<<novavel;

	for(int i (0); i < novavel;i++){
        std::cout<<pk[i];
	}
	return 0;
}
