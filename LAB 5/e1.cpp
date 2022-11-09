#include <iostream>
#include <cmath>
using namespace std;


struct hp{
private:
    long long * a;
    long long capacity;
    long long length;

    void heap_up(long long i){
        if(i > 0){
            long long p_pos = (i - 1) / 2;
            if(a[i] < a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(long long i){
        long long l = 2 * i + 1;
        long long r = 2 * i + 2;
        long long min_pos = i;
        if(l < this->length && a[min_pos] > a[l]) min_pos = l;
        if(r < this->length && a[min_pos] > a[r]) min_pos = r;
        if(i != min_pos) {
            swap(a[i], a[min_pos]);
            heap_down(min_pos);
        }
    }

    void _cut_min(){
        a[0] = a[length - 1];
        length = length - 1 > 0 ? length - 1 : 0;
        heap_down(0);
    }

    void _add(long long x){
        a[length] = x;
        length++;
        heap_up(length - 1);
    }

public:
    hp(long long capacity){
        a = new long long[capacity];
        this->capacity = capacity;
        length = 0;
    }
    
    long long cut_min(){
        long long res = a[0];
        _cut_min();
        return res;
    }

    int add(long long x){
        _add(x);
    }

    void print(){
        for(long long i = 0; i < length; ++i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    int a, b; cin >> a >> b;
    string s;
    int n;
    long long sum = 0;
    hp heap(10000000);

    while (cin >> s)
    {
        if(s == "insert") {
            cin >> n;
            if(n >0) sum += n;
            heap.add(n);
        }
        else cout << sum << endl;
        a--;
        if(a==0) break;

    }
    return 0;
}   