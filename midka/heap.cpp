#include <bits/stdc++.h>

using namespace std;

struct hp{
    private:
    int *a;
    int capacity;
    int length;

    void heap_up(int i){
        if(i > 0){
            int p_pos = (i - 1)/2;
            if(a[i] < a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int min_pos = i;
        if(l < this->length && a[min_pos] > a[l]) min_pos = l;
        if(r < this->length && a[min_pos] > a[r]) min_pos = r;
        if(i != min_pos){
            swap(a[i], a[min_pos]);
            heap_down(min_pos);
        }
    }

    void cut_min(){
        a[0] = a[length-1];
        length = max(length-1, 0);
        heap_down(0);
    }

    void add(int x){
        a[length] = x;
        length++;
        heap_up(length-1);
    }

    public:
    hp(int capacity){
        a = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }
    int _cut_min(){
        int res = a[0];
        cut_min();
        return res;
    }
    void _add(int x){
        add(x);
    }
    void print(){
        for(int i = 0; i < length; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

};





int main()
{
    int n; cin >> n;
    hp h(10000000);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h._add(x);
    }
    for(int i = 0; i < n; ++i){
       cout << h._cut_min() << " "; 
    }
}