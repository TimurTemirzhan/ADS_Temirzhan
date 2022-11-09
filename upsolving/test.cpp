#include <bits/stdc++.h>
#include <string>
using namespace std;




vector<int> bin(int x){
    vector<int> ans;
    while(x > 0){
        ans.push_back(x%2);
        x /= 2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}




int main (){
    int flag = 1;
    cout << flag << endl;
    flag *= (-1);
    cout << flag << endl;
    
    return 0;
}