#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double> v){

    std::vector<std::vector<double>>mat;
    std::vector<double>pomocni;

//...SVI ELEMENTI PO USLOVU...
    for(int i = 1,j = i + 1; i < v.size(),j < v.size();i++,j++){

    if(i - 1 >= 0){
        if(v.at(i) <= v.at(j)){

    //...   1 2 6 7 9 1 7
            pomocni.push_back(v.at(i));
          //  std::cout<<" | "<< v.at(i);
    // std::cout<<"| " << i << ": " << j <<std::endl;
            if( j == v.size() - 1 ) pomocni.push_back(v.at(j));

        }
        if(v.at(i - 1) <= v.at(i) && v.at(i) >= v.at(j) && i - 1 >= 0){
    //...  3 10
            pomocni.push_back(v.at(i));
             // std::cout<<" | "<< v.at(i);
        }

    }
    }

//...PUSH_BACK PRAZAN VEKTOR...
    mat.push_back(std::vector<double>());
//...CITAV VEKTOR ELEMENATA IZ USLOVA....
    int poc = 0, k = 0;
    for(int i = 0, j = i + 1; i < pomocni.size(), j < pomocni.size();i++,j++){
        if(pomocni[i] > pomocni[j]){
          for(int l = poc; l < j; l++){
    // std::cout<<pomocni[l]<<" , ";
           mat[k].push_back(pomocni[l]);
//... DODAJE NOVI PRAZAN...
          }
          mat.push_back(std::vector<double>());
          k++;
    //break;
          poc = j;
        }
//... ZADNJI VEKTOR U MATRICU...
        if(j == pomocni.size() - 1){
           //mat.push_back(std::vector<double>());
           for(int p = poc; p <=j ; p++){
            mat[k].push_back(pomocni[p]);
           }
        }
    }

return mat;
}

//1 3 2 6 7 9 10 4 3 1 7 0

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double> v){

    std::vector<std::vector<double>>mat;
    std::vector<double>pomocni;

//...SVI ELEMENTI PO USLOVU...
    for(int i = 1,j = i + 1; i < v.size(), j < v.size();i++,j++){
        if(i - 1 >= 0){

        if(v.at(i - 1) >= v.at(i) && v.at(i) <= v.at(j)){
        //...   2 1
                //std::cout<< v.at(i-1) << " > " << v.at(i) << " < " << v.at(j) << "\n";
                if(i-1 == 0) pomocni.push_back(v.at(i-1));
                pomocni.push_back(v.at(i));
                if( j == v.size() - 1 ){ pomocni.push_back(v.at(j));  std::cout<<"k";}
        }

        else if(v.at(j) <= v.at(i) && v.at(i) <= v.at(i-1)){

            //std::cout<< v.at(i-1) << " < " << v.at(i) << " > " << v.at(j) << "\n";
    //... 3  10 4 3
            pomocni.push_back(v.at(i));
        //   std::cout<<"|| "<<pomocni[i]<<std::endl;
        // std::cout<<"? "<< i <<std::endl;
         if( j == v.size() - 1 ){ pomocni.push_back(v.at(j));}


        }

    }
    }
    /*for(int i = 0; i < pomocni.size();i++){
        std::cout<<pomocni[i]<<",";
    }*/

//...PUSH_BACK PRAZAN VEKTOR...
    mat.push_back(std::vector<double>());
//...CITAV VEKTOR ELEMENATA IZ USLOVA....
    int poc = 0, k = 0;
    for(int i = 0, j = i + 1; i < pomocni.size(), j < pomocni.size();i++,j++){
        if(pomocni[i] < pomocni[j]){
          for(int l = poc; l < j; l++){
    // std::cout<<pomocni[l]<<" , ";
           mat[k].push_back(pomocni[l]);
//... DODAJE NOVI PRAZAN...
          }
          mat.push_back(std::vector<double>());
          k++;
    //break;
          poc = j;
        }
//... ZADNJI VEKTOR U MATRICU...
        if(j == pomocni.size() - 1){
           //mat.push_back(std::vector<double>());
           for(int p = poc; p <=j ; p++){
            mat[k].push_back(pomocni[p]);
           }
        }
    }

return mat;
}

int main()
{

    double broj;
    std::vector<double>vek;
    std::cout<<"Unesite elemente (0 za kraj): \n";
    while(std::cin >> broj && broj != 0){
        vek.push_back(broj);
    }
    /*
    std::cout<<"Izlaz iz funckije: \n";

    std::vector<double>funk = RastuciPodnizovi(vek);
    for(int i = 0; i < funk.size();i++){
        std::cout<<funk[i]<<" | ";
    }

    int n;
    std::cout<<"Unesite n: \n";
    std::cin>>n;
    std::vector<double>vek;
    std::cout<<"Unesite brojeve: \n";
    for(int i = 0; i < n; i++){
        double br;
        std::cin>>br;
        vek.push_back(br);
    }
    */
    std::cout<<"Rastuci podnizovi: \n";
    std::vector<std::vector<double>>rastuci = RastuciPodnizovi(vek);
    for(int i = 0; i < rastuci.size();i++){
        for(int j = 0; j < rastuci[i].size();j++){
            std::cout<<std::setw(4)<<rastuci[i][j];
        }
        std::cout<<"\n";
    }

    std::cout<<"Opadajuci podnizovi: \n";
    std::vector<std::vector<double>>opadajuci = OpadajuciPodnizovi(vek);
    for(int i = 0; i < opadajuci.size();i++){
        for(int j = 0; j < opadajuci[i].size();j++){
            std::cout<<std::setw(4)<<opadajuci[i][j];
        }
        std::cout<<"\n";
    }

    return 0;
}
