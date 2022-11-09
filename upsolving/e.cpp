#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int maxi(){
    int m = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i]>m) m = v[i];
    }
    return m;
}
int main(){
    int n, x; cin >> n;
    stack <int> st;
    while (n--)
    {
        string s; cin >> s;
        if(s == "add"){
            cin >> x;
            st.push(x);
            v.push_back(x);
        }
        else if(s == "delete"){
            if(!st.empty()) st.pop();
            v.erase(v.end()-1);
        }
        else if(s == "getcur"){
            if(!st.empty()) cout << st.top() << endl;
            else cout << "error" << endl;
        }
        else{
            if(!st.empty()) cout << maxi() << endl;
            else cout << "error" << endl;
        }
    }
    return 0;
}