#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<string, string>, double > a, pair<pair<string, string>, double > b){
    if(a.second == b.second){
        if(a.first.first == b.first.first){
            if(a.first.second == b.first.second) return true;
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
    return a.second < b.second;
}
void merge(pair<pair<string, string>, double > *a, int l1, int r1, int l2, int r2){
    int n1 = r1-l1+1;
    pair<pair<string, string>, double > L[n1];
    for(int i = 0; i < n1; i++){
        L[i] = a[l1+i];
    }
    int n2 = r2-l2+1;
    pair<pair<string, string>, double > R[n2];
    for(int i = 0; i < n2; i++){
        R[i] = a[l2+i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1<n1 && i2<n2){
        if(cmp(L[i1] ,R[i2])) a[i++] = L[i1++];
        else a[i++] = R[i2++];
    }
    while(i1<n1) a[i++] = L[i1++];
    while(i2<n2) a[i++] = R[i2++];
}
void msort(pair<pair<string, string>, double > *a, int l, int r){
    if(l<r){
        int m = r-(r-l)/2;
        msort(a, l, m-1);
        msort(a, m, r);
        merge(a, l, m-1, m, r);
    }
}
int main(){
    int n, cnt; cin >> n;
    pair<pair<string, string>, double > a[n];
    for(int i = 0; i < n; i++){
        string surname, name; cin >> surname >> name >> cnt;
        int credits = 0;
        double gpa = 0;
        for(int j = 0; j < cnt; j++){
            string k; int x;
            cin >> k >> x;
            credits += x;
            if(k == "A+") gpa += 4*x;
            else if(k == "A") gpa += 3.75*x;
            else if(k == "B+") gpa += 3.5*x;
            else if(k == "B") gpa += 3*x;
            else if(k == "C+") gpa += 2.5*x;
            else if(k == "C") gpa += 2*x;
            else if(k == "D+") gpa += 1.5*x;
            else if(k == "D") gpa += 1*x;
            else if(k == "F") gpa += 0*x;
        }
        a[i] = make_pair(make_pair(surname, name), gpa/credits);
    }
    msort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(3) << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
    }
}