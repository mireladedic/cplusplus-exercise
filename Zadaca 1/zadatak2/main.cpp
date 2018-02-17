#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

vector<vector<double>> v(vector<vector<double>> m) {

    for(int k(0), l(m.size()-1); k<int(m.size()/2); k++, l--) {
        swap(m[l], m[k]);
    }
    return m;
}

vector<vector<double>> h(vector<vector<double>> m) {

    for(vector<double> &a : m) {
        for(int i(0), j(a.size()-1); i<(a.size()/2); i++, j--) {
                swap(a[i], a[j]);
            }
        }
    return m;
}

vector<vector<double>> hv(vector<vector<double>> m) {

    return h(v(m));
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>> mat) {

    if(mat.size() == 0)
        throw domain_error("Matrica nije korektna");

    int zadnja_vel=-1;
    for(auto &x : mat) {
        if(zadnja_vel == -1)
            zadnja_vel = x.size();
        if(x.size() == 0)
            throw domain_error("Matrica nije korektna");
        if(zadnja_vel != x.size())
            throw domain_error("Matrica nije korektna");
        zadnja_vel = x.size();
    }
    vector<vector<double>> r;
    vector<vector<double>> h_v = hv(mat);
    vector<vector<double>> v_ = v(mat);
    vector<vector<double>> h_ = h(mat);
    /*
        hv  v   hv
        h   m   h
        hv  v   hv
    */

    // ------------------------ Prvi red ------------------------
    int l = 0;
    vector<double> prazan;
    for(int i(0); i<h_v.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<h_v[i].size(); j++){
                r[l].push_back(h_v[i][j]);
            }
        l++;
    }
    l = 0;
    for(int i(0); i<v_.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<v_[i].size(); j++){
                r[l].push_back(v_[i][j]);
            }
        l++;
    }
    l = 0;
    for(int i(0); i<h_v.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<h_v[i].size(); j++){
                r[l].push_back(h_v[i][j]);
            }
        l++;
    }
    int k = l;
    // ---------------------------- Drugi red ------------------------
    for(int i(0); i<h_.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<h_[i].size(); j++){
                r[l].push_back(h_[i][j]);
            }
        l++;
    }
    l = k;
    for(int i(0); i<mat.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<mat[i].size(); j++){
                r[l].push_back(mat[i][j]);
            }
        l++;
    }
    l = k;
    for(int i(0); i<h_.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<h_[i].size(); j++){
                r[l].push_back(h_[i][j]);
            }
        l++;
    }
    // ----------------------- Zadnji red ----------------
     k = l;
    for(int i(0); i<h_v.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<h_v[i].size(); j++){
                r[l].push_back(h_v[i][j]);
            }
        l++;
    }
    l = k;
    for(int i(0); i<v_.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<v_[i].size(); j++){
                r[l].push_back(v_[i][j]);
            }
        l++;
    }
    l = k;
    for(int i(0); i<h_v.size(); i++) {
            r.push_back(prazan);
            for(int j(0); j<h_v[i].size(); j++){
                r[l].push_back(h_v[i][j]);
            }
        l++;
    }
    return r;
}




int main()
{
    vector<vector<double>> k = {{1,2,3},
                                {4,5,6}};

    for(vector<double> i : OgledaloMatrica(k)) {
        for(double j : i) {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}
