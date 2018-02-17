#include <iostream>
#include <string>
#include<cctype>
bool jelislovo(char c){
    if((c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z')) return true;
    return false;
}

std::string IzdvojiRijec (std::string s, int rednibr){
    std::string rijec,novi;
    int br{0},slovo{0},kraj;


    //... PROLAZIM KROZ STRING SLOVO PO SLOVO
    for(int i (0); i < s.size() ;i++){

    //.... PRESKOCI SVE RAZMAKE - NA POCETKU RECENICE
    /*    while(!jelislovo(s[i]) && i < s.size()){
            i++;
        }
        */
    //...CITAVU RECENICU STAVI U RIJEC BEZ RAZMAKA - IDI DALJE KROZ SLOVA,UKOLIKO NAIDJES NA RAZMAK BROJ RIJECI++
          // int pocetak = 0;
          int pocetak;
        if(jelislovo(s[i])) pocetak = i;
        while(jelislovo(s[i]) &&  i < s.size()){
        //... CITAVA RECENICA SASTAVLJENO - NE TREBA


            rijec.push_back(s[i]);
            i++;
            slovo++;
            //... KRAJ RIJECI-BROJ RIJECI..

            if(s[i] == ' ') {
               // if(i == s.size() - 1) i--; na kraju nesto??

                    br++;

            /*
              if(br == rednibr) {

                novi = s.substr(pocetak,kraj);
                break;
            */
            }
            }

            kraj = i;
            if(br == rednibr) {

                novi = s.substr(pocetak,kraj);
                break;
            }
            //... IZDVOJI MI TU RIJEC I BREAK


            //...   ZADNJA RIJEC
              //   pocetak = i + 1;

             pocetak = kraj;



        }



//    std::cout<<"| "<<slovo<<std::endl;
/*
    for(int i (0); i < s.size();i++){
        novi = (s.substr( i ,s.size() - i))  ;
    }
    */
    std::cout<<"Izdvojeno:\n";
     for(int i  = 0 ; i < novi.size();i++){
            std::cout<<novi[i];
        }
   //std::cout<<"\n| " << br;

}
int main()
{
   std::string s;
   std::cout<<"Unesite recenicu:\n";
   //... IZDVAJA DO OZNAKE KRAJA REDA (ENTER,\n)
   std::getline(std::cin, s);

   std::cout<<"Recenica glasi:\n";
   for(int i(0); i < s.size();i++){
        std::cout<<s[i];
   }

   int rednibr;
   std::cout<<"\nUnesite redni broj rijeci za izdvajanje:\n";
   std::cin >> rednibr;

   std::string izdvojeni = IzdvojiRijec(s,rednibr);
    return 0;
}
