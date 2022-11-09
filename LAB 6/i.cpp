#include <bits/stdc++.h>
using namespace std;
int partition(int *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}
void qsort(int *a, int low, int high){
    if(low<high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}
int main(){
    string s; cin >> s;
    int a[s.size()];
    
    for(int i = 0; i < s.size(); i++){
        a[i] = int(char(s[i]));
    }
    // for(int i = 0; i < n; i++){
    //     cout << char(a[i]);
    // }
    int n = sizeof(a)/sizeof(int);
    qsort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << char(a[i]);
    }

//     if(int((char('b'))<int(char('a')))) cout << 1;
//     else cout << 0;
}