#include <bits/stdc++.h>
using namespace std;

vector<int> bin(long long x){
    vector<int>v;
    while (x>0)
    {
        v.push_back(x%2);
        x /= 2;
    }
    reverse(v.begin(), v.end());
    return v;
}

bool solve(long long x){
    vector<int> v = bin(x);
    if(v.size()%2==1) return false;
    for(int i = 1; i < v.size(); i++){
        if(v[i-1]==1 && v[i]==0){
            v.erase(v.begin()+i-1,v.begin()+i+1);
            i = max(i-2, 0);
        }
    }
    return v.size() == 0;

}
int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        string res = solve(x) ? "YES" : "NO";
        cout << res << endl;
    }
}