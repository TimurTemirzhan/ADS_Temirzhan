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
    string s; cin >> s;
    int cnt = 0;
    vector<size_t> p = f(s);
    for(int i = 1; i < s.size()-1; i+=2){
        if((i+1)%(i+1-p[i]) == 0 && ((i+1)/(i+1-p[i]))%2 == 0) cnt++;
    }
    cout << cnt;
}