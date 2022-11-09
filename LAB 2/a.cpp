#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int diff = 10000000;
    int pos;
    vector <int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int t; cin >> t;
    for(int i = 0; i < v.size(); i++){
        if(abs(v[i]-t)<diff){
            pos = i;
            diff = abs(v[i]-t);
        }
    }
    cout << pos;

}