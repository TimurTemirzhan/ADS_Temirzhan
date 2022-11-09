#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int left = 0, right = 0;
    while(right < n){
        while(abs(a[right] - a[left]) > 3000){
            left++;
        }
        cout << right - left + 1 << ' ';
        right++;
    }
}