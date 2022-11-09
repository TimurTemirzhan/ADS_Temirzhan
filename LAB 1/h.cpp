#include <iostream>
#include <cmath>
using namespace std;
bool func(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
int main()
{
    int n; cin >> n;
    if(n==1){
        cout << "NO";
        return 0;
    }
    func(n);
}