/* TP, 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include <string.h>

int PotencijalniKrivci(char **&a,std::vector<std::string>v){

	try{
		 a = (new char*[v.size()])	;
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
			for(int j(0); j < v[i].size();j++){
				std::cout<<a[i][j]<<" ";
			}
			std::cout<<"\n";
		}
	*/


		//	return a; vrati u pok
		}catch(std::bad_alloc){
			for(int i (0); i < v[i].size(); i++) delete[] a[i];
			delete [] a;
		}
	}catch(...){
		std::cout<<"Nedovoljno memorije!\n";
		throw;
	}

		//...VRATI VELICINU NIZA POKAZIVACA..

		return v.size();
}

int OdbaciOptuzbu(char **&a,int vel,std::string s){
	int brojobrisan{0};

	//...UPOREDI
	for(int i (0); i < vel; i++){
		if( strcmp (a[i],s.c_str() ) == 0 ){
			//....OBRISI NIZ I POKAZIVAC POSTAVI NA NULU
			delete[] a[i];
			a[i] = nullptr;
			brojobrisan++;
		}
	}

	if(brojobrisan > 10){
		//....OBAVI USTEDU MEMORIJE
		char** novi = nullptr;

		try{
			novi = new char *[vel - brojobrisan];
			//..PREKOPIRA SE STARI NIZ POKAZIVACA U NOVI
			novi = a;
			//... UKLONI SE STARI NIZ POKAZIVACA
			a = nullptr;
			//... POSALJE SE NOVI
			a = novi;
		}catch(std::bad_alloc){
			std::cout<<"Novi niz pokazivaca u OdbaciOptuzbu nije alociran!\n";
			for(int i (0); i < vel - brojobrisan; i++)
				delete[] novi[i];

			delete[] novi;

			throw;
		}catch(...){
            std::cout<<"Nedovoljno memorije!\n";
		}
	}

	return vel - brojobrisan;
}

int DodajOptuzbu(char **&a,int vel,std::string s){
	int brojdodan{0};

	char * niz = nullptr;
	try{
		//...DINAMICKI ALOCIRA NIZ
		niz = new char[s.size()];
		//..PREPISI IZ STRINGA U NIZ
		strcpy(niz,s.c_str());

		brojdodan++;
		/*..TEST
		std::cout<<"Dodan: \n";
		for(int i (0);  i < s.size(); i++)
			std::cout<<niz[i];
		*/
	}catch(std::bad_alloc){
		std::cout<<"Niz DodajOptuzbu neuspijesno alociran!\n";
		delete [] niz;
		throw;
	}catch(...){
        std::cout<<"Nedovoljno memorije!\n";
	}

	//...UKOLIKO JE NEKI NULLPTR NA NJEGA ZAKACI NOVI NIZ
	for(int i(0); i < vel;i++){
		if(a[i] == nullptr) a[i] = niz;
	}
	//...U SUPROTNOM NEMA TAKVIH ALOCIRAJ SVE NOVO
	char **novi = nullptr;
	try{
		novi = new char *[vel + brojdodan];
		//..PREPISATI SVE POKAZIVACE IZ STAROG NIZA U NOVI
		novi = a;
		//... NA ZADNJI POKAZIVAC UPISATI ADRESU KREIRANOG NIZA
		a[vel + brojdodan] = niz;
		//...OBRISATI STARI NIZ POKAZIVACA

			delete[] a;
		//.. PARAMETRU POSLATI NOVI
		a = novi;
	}catch(std::bad_alloc){
		std::cout<<"Alokacija novog u DodajOptuzbu nije uspjela!\n";
		for(int i (0); i < vel + brojdodan; i++)
			delete[] novi[i];

			delete [] novi;

			throw;
	}

	return vel + brojdodan;
}


void IzlistajOptuzbu(char ** a,int vel){
	char**pok = a;
	//... UKOLIKO JE NEKI PARAMETAR NULL TREBA GA IGNORIRATI...
	for(int i (0); i < vel;i++){
		if(pok[i] == nullptr) continue;
		std::cout<<pok[i]<<std::endl;
	}
}


int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?\n";
	int n;
	std::cin>>n;
    std::cin.ignore(10000,'\n');


	std::cout<<"Unesite potencijalne krivce:\n";
	std::vector<std::string>sp;
	std::string s;

	for(int i (0); i < n; i++){
		std::getline(std::cin,s);
		sp.push_back(s);
	}


	try{
	//...PRVA FUNK
			char**pk = nullptr;
			int vel = 	PotencijalniKrivci(pk,sp);


	//...ODABERITE OPCIJU....

	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:\n";
	int opcija;
	std::cin >> opcija;


    if(opcija == 1){
        std::cout<<"Unesite ime novog optuzenog:\n";
		std::string c;
		std::getline(std::cin,c);

        try{
            vel = DodajOptuzbu(pk,vel,c);
        }catch(std::bad_alloc izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }

    }


    if(opcija == 2){
        std::cout<<"Unesite ime koje zelite izbaciti:\n";
        std::string p;
        std::getline(std::cin,p);

        try{
            vel = OdbaciOptuzbu(pk,vel,p);
        }catch(std::bad_alloc izuzetak ){
            std::cout<<izuzetak.what()<<std::endl;
        }

    }

    if(opcija == 3){

        IzlistajOptuzbu(pk,vel);
    }

    if(opcija == 0){
        std::cout<<"Kraj\n";
    }




    }catch(std::bad_alloc izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
