#include <iostream>
using namespace std;

bool bs(int a[], int n, int x)
{
    int l = 0; int r = n-1;
    while (l<=r)
    {
        int mid = l + (r-l)/2;
        if(a[mid] > x) r = mid-1;
        else if(x == a[mid]) return 1;
        else l = mid+1;
    }
    return 0;
    

}
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x; cin >> x;

    string res = bs(a, n, x) ? "Yes" : "No";
    cout << res;

    return 0;
}