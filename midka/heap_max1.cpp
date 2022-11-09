#include <bits/stdc++.h>
using namespace std;
struct heap{
    private:
    int *a, capacity, length;

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
        if(l < this->length && a[min_pos] < a[l]) min_pos = l;
        if(r < this->length && a[min_pos] < a[r]) min_pos = r;
        if (i != min_pos){
            swap(a[i], a[min_pos]);
            heap_down(min_pos);
        }
    }
    void cut_max(){
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
    heap(int capacity){
        a = new int[capacity];
        length = 0;
        this->capacity = capacity;
    }
    void _add(int x){

        add(x);

    }
    int _cut_max(){
        int res = a[0];
        cut_max();
        return res;
    }
    void print()
    {
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
        hp._add(x);
    }
    for(int i = 0; i < n;i++){
        cout << hp._cut_max() << " ";
    }
    cout << endl;
    return 0;
}