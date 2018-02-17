/*zadatak9.1*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool daLiJeProst(int a) {
    int i;
    bool prost = true;
    for (i=2; i<=sqrt(a); i++) {
        if (a%i == 0) {
            prost = false;
        break;
        }
    }
    return prost;
 }

int main()
{
    int n;
    vector<int> brojevi;
    cin >> n;

    int br = 1;
    while(br < n) {
       br++;
       if(daLiJeProst(br) && n % br == 0 ) {

            brojevi.push_back(br);
       }
    }

    for(int i(0); i<brojevi.size(); i++) {
        cout << brojevi.at(i) << endl;
    }

    return 0;
}
