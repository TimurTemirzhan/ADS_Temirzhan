#include <bits/stdc++.h>
using namespace std;

vector <size_t> f(string str){
    size_t n = str.size();
    vector <size_t> v(n);
    v[0] = 0;
    for(int i = 1; i < n; i++){
        size_t j = v[i-1];
        while (j>0 && str[j] != str[i]) j = v[j-1];
        if(str[i] == str[j]) v[i] = j+1;
    }
    return v;
}

// bool check(vector <size_t> p, int sz){
//     for(int i = 0; i < p.size(); i++) if(p[i] == sz) return true;
//     return false;
// }

int main(){
    string s; cin >> s;
    vector <size_t> v = f(s + "#" + s);
    // for(int i = 0; i < v.size(); i++){
    //     if(v[i] != 0 && v[i+1] == 0) cout << s.size() - v[i];
    // }
    cout << v[v.size()-1] - v[s.size()-1];

}