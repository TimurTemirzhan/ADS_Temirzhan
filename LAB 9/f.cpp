#include <bits/stdc++.h>
using namespace std;

vector <size_t> f(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    for(size_t i = 1; i < n; i++){
        size_t j = v[i-1];
        while (j>0 && str[j] != str[i]) j = v[j-1];
        if(str[i] == str[j]) v[i] = j+1;
    }
    return v;
}

int main(){
    string s, t; cin >> t >> s;
    string str = s + '#' + t;
    vector <size_t> v = f(str);
    vector <size_t> res;
    for(int i = 0; i < v.size(); i++) if(v[i] == s.size()) res.push_back(i-s.size()-s.size()+1);
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}