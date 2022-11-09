#include <iostream>
using namespace std;
int bs_odd_i(int a[], int n, int x){
    int m;
    int l = 0;
    int h = n-1;
    while (l <= h)
    {
        m = l+(h-l)/2;
        if(a[m]>x) h = m-1;
        else if(a[m] == x) return m;
        else l = m + 1;
    }
    return -1;
}

int bs_even_i(int a[], int n, int x){
    int m;
    int l = 0;
    int h = n-1;
    while (l <= h)
    {
        m = l+(h-l)/2;
        if(a[m]>x) l = m+1;
        else if(a[m] == x) return m;
        else h = m - 1;
    }
    return -1;
}

int main()
{
    int t; cin >> t;
    int a[t];
    for(int i = 0; i < t; ++i){
        cin >> a[i];
    }
    int n, m; cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int c = 0; c < t; ++c){
        for(int i = 0; i < n; ++i){
            int ind = 0;
            if(i%2 == 1) ind = bs_odd_i(arr[i], m, a[c]);
            else ind = bs_even_i(arr[i], m, a[c]);

            if(ind != -1){
                cout << i << " " << ind << endl;
                break;
            }
            else if(ind == -1 and i == n-1) cout << ind << endl;
        }
         
    }
}