#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int,int> > pivot){
    if(a.first == pivot.first){
        if(a.second.second == pivot.second.second){
            if(a.second.first == pivot.second.first) return true;
            return a.second.first < pivot.second.first;
        }
        return a.second.second < pivot.second.second;
    }
    return a.first < pivot.first;
}
int partition(vector<pair<int, pair<int, int> > > &v, int low, int high){
    pair<int, pair<int, int> > pivot = v[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(cmp(v[j], pivot)){
            i++;
            swap(v[j], v[i]);
        }
    }
    swap(v[i+1],v[high]);
    return i+1;
}
void qsort(vector<pair<int, pair<int, int> > > &v, int low, int high){
    if(low<high){
        int pivot = partition(v, low, high);
        qsort(v, low, pivot-1);
        qsort(v, pivot+1, high);
    }
}
int main(){
    int n, i; cin >> n;
    vector <pair<int, pair<int, int> > > v;

    for(i = 0; i < n; i++){
        int day, mon, year;
        char c;
        cin >> day >> c >> mon >> c >> year;
        v.push_back(make_pair(year, make_pair(day, mon)));
    }
    qsort(v, 0, v.size()-1);
    for(i = 0; i < v.size(); i++){
        (v[i].second.first < 10) ? cout << 0 << v[i].second.first << "-" : cout << v[i].second.first << "-";
        (v[i].second.second < 10) ? cout << 0 << v[i].second.second << "-" : cout << v[i].second.second << "-";
        cout << v[i].first << endl;
    }
}