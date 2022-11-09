#include <bits/stdc++.h>
using namespace std;
vector <int> v;
struct heap{
    private:
    int *a, len, cap;

    void heap_up(int i){
        if(i>0){
            int p_pos = (i-1)/2;
            if(a[p_pos] < a[i]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }
    void heap_down(int i){
        int l = 2*i+1;
        int r = 2*i+2;
        int min_pos = i;
        if(l < this->len && a[min_pos] < a[l]) min_pos = l;
        if(r < this->len && a[min_pos] < a[r]) min_pos = r;
        if(i != min_pos){
            swap(a[i], a[min_pos]);
            heap_down(min_pos);
        }
    }
    void cut_max(){
        a[0] = a[len-1];
        len = max(len-1, 0);
        heap_down(0);
    }
    void add(int x){
        a[len] = x;
        len++;
        heap_up(len-1);
    }

    public:
    // void _heap_up(){
    //     heap_up();
    // }
    heap(int cap){
        a = new int[cap];
        this->cap = cap;
        len = 0;
    }
    int _cut_max(){
        int res = a[0];
        cut_max();
        return res;
    }
    void _add(int x){
        add(x);
    }
    void print(){
        for(int i = 0; i < len; i++){
            cout << a[i] << " ";
        }
    }
    int get_len(){
        return len;
    }
    int solve(int i, int g){
        int save = a[i-1];
        a[i-1] += g;
        heap_up(i-1);
        for(int i = 0; i < len; i++){
            if(save + g == a[i]) cout << i+1 << endl;
        }
    
    }
};

int main()
{
    int n; cin >> n;
    heap h(1000000);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h._add(x);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int ind, plus; cin >> ind >> plus;
        h.solve(ind, plus);
    }
    h.print();
}