#include <bits/stdc++.h>
using namespace std;

bool cmp(pair < string, int > a, pair < string, int > b){
    return a.second <= b.second;
}

void merge(pair<string, int> *a, int l1, int r1, int l2, int r2){
    int n1 = r1-l1+1;
    int n2 = r2-l2+1;
    pair< string, int> L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = a[l1+i];
    for(int i = 0; i < n2; i++) R[i] = a[l2+i];
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1<n1 && i2<n2){
        if(cmp(L[i1], R[i2])) a[i++] = L[i1++];
        else a[i++] = R[i2++];
    }
    while(i1<n1) a[i++] = L[i1++];
    while(i2<n2) a[i++] = R[i2++];
}
void msort(pair<string, int> *a, int l, int r){
    if(l<r){
        int m = r-(r-l)/2;
        msort(a, l, m-1);
        msort(a, m, r);
        merge(a, l, m-1, m, r);
    }
}
int main(){
    
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        vector <string> v;
        string s, g; getline(cin, s);
        if(i!=0){ 
        for(int i = 0; i < s.size(); i++){
            if(i+1 == s.size()){
                g += s[i];
                v.push_back(g);
            }
            else if(s[i] == ' ') {
                v.push_back(g);
                g = "";
            }
            else g += s[i];
        }

        pair<string, int> a[v.size()];
        for(int i = 0; i < v.size(); i++){
            a[i] = make_pair(v[i], v[i].size());
        }

        msort(a, 0, v.size()-1);

        for(int i = 0; i < v.size(); i++){
            cout << a[i].first << " ";
        }
        cout << endl;
        }
    }
    return 0;
}