#include <iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    int m[n];
    int odd = 0;
    int even = 0;

    for(int i = 0; i < n; i++){
        cin >> m[i];
        if(m[i] % 2 == 0) even++;
        else odd++; 
    }
    cout << even << " " << odd;

}