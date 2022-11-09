#include <bits/stdc++.h>
using namespace std;
int partition(int *a, int low, int high){
    int i = low-1;
    int pivot = high;
    for(int j = low; j < high; j++){
        if(a[j] < a[pivot]){
            i++; 
            swap(a[i], a[j]);
        }
    }
    swap(a[pivot], a[i+1]);
    return i+1;
}
void qsort(int *a, int low, int high){
    if(low<high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, high);
    }
}
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int a[n];
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') a[i] = 93;
        else if(s[i] == 'e') a[i] = 94;
        else if(s[i] == 'i') a[i] = 95;
        else if(s[i] == 'o') a[i] = 96;
        else if(s[i] == 'u') a[i] = 97;
        else a[i] = int(s[i]);
    }
    qsort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        if(a[i] == 93) cout << 'a';
        else if(a[i] == 94) cout << 'e';
        else if(a[i] == 95) cout << 'i';
        else if(a[i] == 96) cout << 'o';
        else if(a[i] == 97) cout << 'u';
        else cout << char(a[i]);
    }
}