#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int partition(int *a, int low, int high){
    int pivot = high;
    int i = low -1;
    for(int j = low; j < high; ++j){
        if(a[j]<a[pivot]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[pivot], a[i+1]);
    return i+1;
}
void qsort(int *a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, high);
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
    // for(int i = 0; i < n; i++){
    //     cout << a[i];
    // }

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

    int c[v.size()];
    for(int i = 0; i < v.size(); i++){
        c[i] = v[i];
    }

    qsort(c, 0, v.size()-1);
    for(int i = 0; i < v.size(); i++){
        cout << c[i] << " ";
    }
}