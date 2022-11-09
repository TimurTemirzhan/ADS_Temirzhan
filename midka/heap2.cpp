#include <bits/stdc++.h>

using namespace std;
struct heap{
    private:
    int *a;
    int capacity;
    int length;

    void _heap_up(int i){
        if(i > 0){
            int p_pos = (i-1)/2;
            if(a[i] < a[p_pos]){
                swap(a[i], a[p_pos]);
                _heap_up(p_pos);
            }
        }
    }

    void _heap_down(int i){
        int l = 2*i +1;
        int r = 2*i +2;
        int min_pos = i;
        if(l < this->length && a[min_pos] > a[l]) min_pos = l;
        if(r < this->length && a[min_pos] > a[r]) min_pos = r;
        if(i != min_pos){
            swap(a[i], a[min_pos]);
            _heap_down(min_pos);
        }
    }

    void _cut_min(){
        a[0] = a[length-1];
        length = max(length-1, 0);
        _heap_down(0);
    }

    void _add(int x){
        a[length] = x;
        length++;
        _heap_up(length-1);
    }

    public:
    heap(int capacity){
        a = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }
    int cut_min(){
        int res = a[0];
        _cut_min();
        return res;
    }
    void add(int x){
        _add(x);
    }
    void print(){
        for (int i = 0; i < length; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

};
int main()
{
    int n; cin >> n;
    heap hp(10000000);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        hp.add(x);
    }
    for ( int i = 0; i < n; i++){
        cout << hp.cut_min() << " ";
    }
    // hp.print();
}