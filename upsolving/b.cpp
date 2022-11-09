#include <bits/stdc++.h>
using namespace std;
vector<int>v;
bool isprime(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i==0) return 0;
    }
    return true;
}
int main()
{
    int n; cin >> n;
    for(int i = 2; i < 100000; i++) if(isprime(i)) v.push_back(i);
    for(int i = 0; i < n; i++){
        if(isprime(n-v[i])){
            cout << v[i] << " " << n-v[i];
            break;
        }
    }
}