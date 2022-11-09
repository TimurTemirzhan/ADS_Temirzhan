#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &a, int l1, int r1, int l2, int r2){
    int n1 = r1-l1+1;
    int L[n1];
    for(int i = 0; i < n1; i++){
        L[i] = a[l1+i];
    }

    int n2  = r2-l2+1;
    int R[n2];
    for(int i = 0; i < n2;i++){
        R[i] = a[l2+i];
    }
    
    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]) a[i++] = L[i1++];
        else a[i++] = R[i2++];
    }

    // copy rest of L and R
    while(i1<n1) a[i++] = L[i1++];
    while(i2<n2) a[i++] = R[i2++];

}

void msort(vector <int> &a, int l, int r){
    if(l<r){
        int m = r-(r-l)/2;
        msort(a, l, m-1);
        msort(a, m, r);
        merge(a, l, m-1, m, r);
    }
}

int main(){
    vector <int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    msort(a, 0, a.size()-1);

    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }

    return 0;
}