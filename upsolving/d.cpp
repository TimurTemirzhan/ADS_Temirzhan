#include <bits/stdc++.h>
using namespace std;
set <int> s;
int solve(int n){  
  int i = 2;
  while (n > 1)
  {
    if (n % i == 0){
      s.insert(i);
      n /= i;
    }
    else i++;
  }
  return s.size();
}
int main()
{
    int n; cin >> n;
    solve(n);
    cout << s.size();
}