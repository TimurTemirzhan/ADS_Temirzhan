#include <bits/stdc++.h>
using namespace std;
vector <int> v;
void merge(vector <int> &v, int l1, int r1, int l2, int r2){
    int n1 = r1-l1+1;
    int n2 = r2-l2+1;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = v[l1+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = v[l2+i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while (i1<n1 && i2<n2){
        if(L[i1]<R[i2]) v[i++] = L[i1++];
        else v[i++] = R[i2++];
    }
    while(i1<n1) v[i++] = L[i1++];
    while(i2<n2) v[i++] = R[i2++];
}
void msort(vector <int> &v, int l, int r){
    if(l<r){
        int m = r-(r-l)/2;
        msort(v, l, m-1);
        msort(v, m, r);
        merge(v, l, m-1, m, r);
    }
}
int main(){ 
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    if(n==0 or m == 0) return 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                v.push_back(a[i]);
                b[j] = -1;
                break;
            }
        }
    }

    msort(v, 0, v.size()-1);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}