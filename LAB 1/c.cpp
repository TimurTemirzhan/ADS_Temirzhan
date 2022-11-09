#include <iostream>
using namespace std;

int main()
{
    string s, g; cin >> s >> g;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '#')
        {
            s.erase(i-1, 2);
            i -= 2;
        }
    }
    
    for(int i = 0; i < g.size(); i++)
    {
        if(g[i] == '#')
        {
            g.erase(i-1, 2);
            i -= 2;
        }
    }
    if(s==g) cout << "Yes";
    else cout << "No";
}