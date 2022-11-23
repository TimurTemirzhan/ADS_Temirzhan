#include <bits/stdc++.h>
using namespace std;
vector <string> q;
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
vector <pair<string, int> > res;
int main(){
    string p; cin >> p;
    int n; cin >> n;
    p[0] += 32;
    int m = 1;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        s[0] += 32;
        int max = 0;
        vector <size_t> v = f(s + '#' + p);
        if(v[v.size()-1] >= max){
            res.push_back(make_pair(s, v[v.size()-1]));
            max = v[v.size()-1];
        }
        if(m < max) m = max;

        
    }
    vector <string> ans;
    for(int j = 0; j < res.size(); j++){
        if(res[j].second == m){
            res[j].first[0] -= 32;
            ans.push_back(res[j].first);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}