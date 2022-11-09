#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> v;

int main()
{
    int n; cin >> n;
    int a, p;

    while(cin >> a)
    {
        if(a == 1){
            cin >> p;
            v.push_back(p);
        }
        else reverse(v.begin(), v.end());
        n--;
        if(n == 0) break;
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

}