#include <bits/stdc++.h>
using namespace std;
int partition(int *a, int low, int high){
    int i = low-1;
    int pivot = high;
    for(int j = low; j < high; ++j){
        if(a[j] < a[pivot]){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i+1], a[pivot]);
    return i+1;
}
void qsort(int *a, int low, int high){
    if(low<high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, high);
    }
}

vector<int>v;

int main(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }

    int q[n];
    int cnt = 0;
    for(int k = 0; k < m; k++){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j==cnt) q[i] = a[i][j];
            }
        }
        qsort(q, 0, n-1);
        for(int p = 0; p < n; p++) v.push_back(q[p]);
        cnt++;
    }
    // qsort(q, 0, n-1);
    // for(int p = 0; p < n; p++){
    //     cout << q[p] << " ";
    // }
    // for(int p = 0; p < v.size(); p++){
    //      cout << v[p] << " ";
    // }
    // 3-7-11   
    // 2-6-10   
    // 1-5-9   
    // 0-4-8

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << v[j*n-i] << " ";
        }
        cout << endl;
    }

}