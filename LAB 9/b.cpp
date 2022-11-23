#include <bits/stdc++.h>
using namespace std;

vector <size_t> f(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++){
        size_t j = v[i-1];
        while (j>0 && str[j] != str[i]) j = v[j-1];
        if(str[i] == str[j]) v[i] = j+1;
    }
    return v;
}

int main(){
    string s, t;
    int k; cin >> s >> k >> t;
    string str = s + '#' + t;
    vector <size_t> v = f(str);
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) if(v[i] == s.size()) cnt++;
    cnt >= k ? cout << "YES" : cout << "NO";
    return 0;
}