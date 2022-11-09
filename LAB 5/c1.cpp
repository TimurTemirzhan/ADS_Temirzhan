#include <bits/stdc++.h>
using namespace std;

struct heap{
    private:
    int *a, cap, len;
    
    void heap_up(int i){
        if(i > 0){
            int p_pos = (i-1)/2;
            if(a[i] > a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i){
        int l = 2*i+1;
        int r = 2*i+2;
        int min_pos = i;
        if(l < this-> len && a[min_pos] < a[l]) min_pos = l;
        if(r < this-> len && a[min_pos] < a[r]) min_pos = r;
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
};

int main()
{
    int n, k; cin >> n >> k;
    heap hp(100000);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        hp._add(x);
    }
    while (k--)
    {
        int max = hp._cut_max();
        sum += max;
        hp._add(max-1);
    }

    cout << sum;
    
    return 0;
}