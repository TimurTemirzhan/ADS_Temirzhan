#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
vector <int> v;
int summ(int n, int x)
{
    int s = 0;
    for(int i = 0; i < n; i++){
        if(v[i]%x == 0 and v[i] >= x) s += v[i]/x;
        else s += (v[i]/x) +1;
    }
    return s;
}
int main()
{
    int n, h; cin >> n >> h;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }


    int l = 1;
    int r = pow(10,9);
    int mid, ans;
    ans = r;
    while (l<=r)
    {
        mid = l + (r-l)/2;
        if(summ(n, mid) <=h){
            ans = min(ans, mid);
            r = mid-1;
        }
        else l = mid +1;
    }
    cout << ans;
    
}