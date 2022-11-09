#include <bits/stdc++.h>
using namespace std;
map <string, string> m;
int main(){
    int n; cin >> n;
    pair<string, string> a[n];
    for(int i = 0; i < n; i++){
        string old, new_; cin >> old >> new_;
        a[i] = make_pair(old, new_);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i].second == a[j].first){
                a[i].second = a[j].second;
                a[j].first = '-';
                a[j].second = '-';
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i].first != "-"){
            m.insert(pair<string, string>(a[i].first, a[i].second));
        }
    }
    map<string, string>::iterator it = m.begin();
    cout << m.size() << endl;
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}