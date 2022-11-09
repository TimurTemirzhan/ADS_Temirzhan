#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    int cnt1;
    for(int i = 4; i <= n; i++){
        int cnt = 0;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0) cnt++;
        }
        if(cnt == 1) cnt1++;
    }
    cout << cnt1;

    return 0;
}