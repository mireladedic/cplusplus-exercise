#include <iostream>
#include <string>

bool slovo(char c){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}
/*
int brojac (std::string s){
    int br (0);
    for(int i (0) ; i < s.size();i++){

        if( ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && (s[i - 1]== ' ' || s[i] == '\0') ){

            while( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ) i++;

            if(s[i] == ' ' || s[i] == '\0') {
                br++;
            }

        }
    }
    return br;
}
*/
std::string izdvoji (std::string s,int br){

    std::string blank,lett;
    int brojrijeci(0),pocetak,kraj;
    for(int i (0); i < s.size();i++){
      //... DOCI CE NA POCETAK RIJECI...
      //... SVI RAZMACI...
    /*
        while(!slovo(s[i])){
            blank.push_back(s[i]);
            i++;
        }
    */
     //...SAMO SLOVA
        while(slovo(s[i]) && i < s.size()){
            pocetak = i; //... PRVO SLOVO TE RECENICE
          //  lett.push_back(s[i]);
         //   i++;

            while(slovo(s[i])){
                i++;
                if(i == s.size() - 1) {kraj = i - 1;}
            }

            kraj = i;
            brojrijeci++;

            if(brojrijeci == br){
                lett = s.substr(pocetak,kraj);
            }
            i = kraj;

            /*
            if(s[i] == ' '){
              //  lett.push_back(s[i]);
                kraj = i;
                brojrijeci++;
            */
                // --- SLUCAJEVI-IZDVOJI RIJEC---
            //.... UKOLIKO JE PRVA RIJEC

            //... UKOLIKO JE RIJEC U SREDINI..

            //... UKOLIKO JE RIJEC NA KRAJU..



              //  pocetak = kraj;
              //  i++;
            }

        }

//    }

    /*
    std::cout<<"Blanko: \n";
    for(int i(0); i < blank.size();i++){
        std::cout<<blank[i]<<"|";
    }
    */
    std::cout<<"Lett: \n";
    for(int i (0); i <lett.size();i++){
        std::cout<<lett[i]<<"|";
    }

    return lett;
}
int main()
{
    int redni;
    std::cout<<"Unesite broj: \n";
    std::cin>>redni;

    std::cin.ignore(10000,'\n');

    std::cout<<"Unesite recenicu:\n";
    std::string s;
    std::getline(std::cin,s);

    std::string rijec = izdvoji(s,redni);


/*
    int brojrijeci = brojac(s);
    std::cout<<"| "<<brojrijeci;
*/
    return 0;
}
