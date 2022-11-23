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

bool check(vector <size_t> p, int sz){
    for(int i=0; i<p.size(); i++) if(p[i] == sz) return true;
    return false;
}

int main(){
    string s, t; 
    cin >> s >> t;

    string add = s;
    int cnt = 1;
    while(s.size() < t.size()){
        s += add;
        cnt++;
    }
    
    vector <size_t> p = f(t + '#' + s);
    if(check(p, t.size())) cout << cnt;
    else{
        s += add;
        p = f(t + '#' + s);
        if(check(p, t.size())) cout << cnt + 1;
        else cout << -1;
    }
    return 0;
}