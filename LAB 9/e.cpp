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
    int n, k; cin >> n;
    while(n--){
        string s; cin >> s >> k;
        int ans = s.size();
        int r = f(s)[ans-1];
        ans += (ans-r)*(k-1);
        cout << ans << endl;
    }
}