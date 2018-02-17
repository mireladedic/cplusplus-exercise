#include <iostream>
#include <vector>
#include <cmath>

//...LINIJA 75 ISPADA IZ OPSEGA, 65 I -65 GLEDA ISTO PA IH IZBACUJE, UVRSTITI SLUCAJ KADA NISU NI JEDNI NI DRUGI...
/*
bool PrebrojiElemente (std::vector<int>baza){
     //... PREBROJI ELEMENETE...


    for(int i = 0; i < baza.size(); i++){
            int brojac {1};
        for(int j = i + 1 ; j < baza.size(); j++){
            //std::cout<<i<<" : "<<j << "\n";

            if(baza[i] == baza[j] ){
            //std::cout<< baza[i] << " : " << baza[j]<< std::endl;
                brojac++;
             }
            //std::cout<<" | " << j ;
        }
            vektbr.push_back(brojac);

            //...OGRANICI DA NE UZIMA U OBZIR ISTE BROJEVE...
    }
*/



bool Baza3 (int n){

    int br = std::abs(n);
    std::vector <int> baza;

    //... BINARNO POZITIV...

        while(br != 0){
            int b = br % 3;
            baza.push_back(b);
            br /= 3;
        }


    //...   REVERSE VEKTOR SWAP ELEMENTE...
    for(int i = 0, j = baza.size()- 1; i < baza.size(), j > 0 ; i++,j--){
        std::swap(baza[i],baza[j]);
    }
    //... NEGATIVNI BROJEVI KOMPLEMENT BAZE 3...
    if(n < 0){
        for(int i = baza.size() -1; i >= 0; i--){
            if(baza.size() - 1) baza[i] = 3 - baza[i];
            else baza[i] = 2 - baza[i];
        }
        /* .... ISPISI NEGATIVNE ....
            std::cout<<"neg \n";
            for(int i = 0; i < baza.size();i++){
            std::cout<<baza[i]<< " ";
        }
        */
    }

    /* SWAP PRI ISPISU
        for(int i = baza.size() - 1; i >= 0; i--){
            std::cout<<baza[i]<< " | ";
    }

        ...POZIV POMOCNE FUNKCIJE...
     bool logika = PrebrojiElemente(baza);
     std::cout<<"\ntrue ili false = " << std::boolalpha<< logika<<std::endl;
    //... VRATI..
    return baza;
    */

    //...PREBROJI ELEMENTE ...

    std::vector<int> vektbr;
    int br0{0},br1{0},br2{0};

        for(int i = 0; i < baza.size();i++){
            if(baza[i] == 0 ) br0++;
            else if (baza[i] == 1) br1++;
            else br2++;
        }
    if(br0 > 0) vektbr.push_back(br0);
    if(br1 > 0) vektbr.push_back(br1);
    if(br2 > 0) vektbr.push_back(br2);


    //...PARNI ILI NEPARNI...SVI
    bool jeste;
        for(int i = 0; i < vektbr.size();i++){
            if(vektbr[i] % 2 != 0 ){ jeste = false; break;}
            else jeste = true;
        }

    //if(jeste) return n;

    /* ...ISPISI VEKTOR BROJACA...
    std::cout<<"brojaci: \n";
    for(int i = 0; i < vektbr.size();i++){
        std::cout<<vektbr[i]<< " ";
    }
    */
return jeste;

}


std::vector<int> IzdvojiGadne(std::vector<int> gadni , bool parametar){
    std::vector<int>opaki;
    std::vector<int>odvratni;

     //...BEZ PONAVLJANJA...IZBACI ELEMENTE ...
    for(int i = 0; i < gadni.size();i++){
            for(int j = i + 1 ; j < gadni.size() ;j++){
                if(gadni[i] == gadni[j]){

                    gadni[j] = gadni[j + 1];
                    gadni.resize(gadni.size() - 1);
                      i--;
                }
            }
    }


    for(int i = 0; i < gadni.size(); i++){
        std::cout<<gadni[i] << " | ";
    }
    std::cout<<"\n";

    //...POZOVI FUNKCIJU I STAVI U VEKTOR...
    for(int i = 0; i < gadni.size();i++){
        if(Baza3(gadni[i])) {
            opaki.push_back(gadni[i]);
        }
        else // if(!Baza3(gadni[i]))
        {
            odvratni.push_back(gadni[i]);

        }

    }



    //...U OVISNOSTI OD PARAMETRA VRATI TAJ VEKTOR...
   if(parametar) return opaki;
   else return odvratni;
}

int main()
{
    // ... UNOS ELEMENATA U VEKTOR ...
    std::cout<<"Unesite n: \n";
    int n;
    std::cin >> n;

    std::cout<<"Unesite : \n";
    std::vector<int>gadni;
    for(int i = 0; i < n; i++){
        int br;
        std::cin >> br;
        gadni.push_back(br);
    }

    //....POZIV FUNKCIJE ..
    std::cout<<"Unesite parametar: \n";
    bool parametar;
    std::cin >> parametar;

    std::vector<int>izdvoji = IzdvojiGadne(gadni,parametar);

    //... ISPISI...
    std::cout<<"Gadni : \n";
    for(int i = 0; i < izdvoji.size();i++){
        std::cout<<izdvoji[i]<<" ";
    }

    /*
        std::vector<int> b = Baza3(n);

        std::cout<<"\nbin baza3\n";
        for(int i = 0; i< b.size();i++){
        std::cout<<b[i]<<" ";
    }
    */

    return 0;
}
