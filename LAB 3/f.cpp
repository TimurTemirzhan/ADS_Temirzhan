#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int p; cin >> p;
    for(int i = 0; i < p; i++){
        int k; cin >> k;
        int cnt_power = 0;
        int cnt_competitor = 0;
        for(int j = 0; j < v.size(); j++){
            if(k>=v[j]){
                cnt_competitor++;
                cnt_power += v[j];
            }
        }
        cout << cnt_competitor << "  " << cnt_power << endl;
    }
    
    return 0;
}