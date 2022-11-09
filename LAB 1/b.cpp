#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int vec(int n)
{
    int min = 1e9;
    for(int i = 0; i < n; i++)
    {
        if(v[i]<min) {
            min = v[i];
            cout << "-1 ";
        }
        else 
        {
            for(int j = i-1; j >= 0; j--){
                if(v[j] <= v[i]) 
                {
                    cout << v[j] << " ";
                    break;
                }
            }
        }
    }
}
int main()
{
    
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    vec(n);
}