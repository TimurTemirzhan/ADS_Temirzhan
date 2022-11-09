#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector <int> v, v2;
int func(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    v.push_back(n);
    return 0;
}

int main()
{
    int i = 2;
    int n; cin >> n;

    while(true)
    {
        func(i);
        i++;
        if (v.size() > 999) break;
    }
    // cout << v[n-1];
    cout << v[v[n-1]-1];
}
