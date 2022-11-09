#include <bits/stdc++.h>
using namespace std;
string b(int n){
    string bin = "";
    while (n != 0)
    {
        bin += to_string(n%2);
        n /= 2; 
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

bool check(int n){
    string bin = b(n);
    if (bin.size() % 2 == 1) return false;

    for (int i = 1; i < bin.size(); i++){
        if (bin[i] == '0' && bin[i-1] == '1'){
            bin.erase(i-1,i+1);
            i = max(i-2,0);
        }
    }
    return bin.size() == 0;
}



int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        string res = check(x) ? "YES" : "NO";
        cout << res << endl;
    }
}