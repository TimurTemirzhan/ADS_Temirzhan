#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        a[i] = c;
    }
    char t; cin >> t;
    for(int i = 0; i < n; i++){
        if(a[i] > int(t)){
            cout << char(a[i]);
            break;
        }
        else if(a[i] == int(t) && a[i] != a[n-1]){
            cout << char(a[i+1]);
            break;
        }
        else if(a[i] == a[n-1]){
            cout << char(a[0]);
            break;
        }
    }
    
}