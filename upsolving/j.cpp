#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n, int t){

    for(int i = 0; i < n; i++){
        int l = 0;
        int r = n-1;
        while (l<=r)
        {
            int m = l+((r-l)/2);
            if(a[i]+a[m]>t) r = m-1;
            else if(a[i]+a[m]<t) l = m+1;
            else if(a[i]+a[m]==t) {
                cout << a[i] << " " << a[m];
                return 0;
            }
        }
        
    }
}
int main(){
    int t; cin >> t;
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    solve(a,n,t);

    return 0;
}