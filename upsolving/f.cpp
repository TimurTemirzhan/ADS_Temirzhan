#include <iostream>

using namespace std;

struct max_heap
{
    private:
    int *a;
    int len, cap;

    void heap_up(int i ){
        if (i > 0){
            int p_pos = (i-1)/2;
            if (a[p_pos] < a[i]){
                swap(a[p_pos],a[i]);
                heap_up(p_pos);
            }
        }
    }

    void _add(int x){
        a[len] = x;
        len++;
        heap_up(len-1);
    }

    void _cut_min(){
        a[0] = a[len-1];
        len = max(len-1,0); 
        heap_down(0);
    }

    void heap_down(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if (l < len && a[l] > a[min_pos]) min_pos = l;
        if (r < len && a[r] > a[min_pos]) min_pos = r;
        if (i != min_pos){
            swap(a[i],a[min_pos]);
            heap_down(min_pos);
        }
    }

    public:
    max_heap(int cap){
        a = new int[cap];
        this->cap = cap;
        len = 0; 
    }
     void add(int x){
        _add(x);
     }

    int cut_min(){
        int res = a[0];
        _cut_min();
        return res;
    }
    int res(){
        int cnt = 0;
        for (int i = 0; i < len; i++){
            if (a[2*i+1] < a[2*i+2] && 2*i+1 < len && 2*i+2 < len){
                cnt++;
            }
        }
        return cnt;
    }
};







int main (){
    max_heap hp(1000000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        hp.add(x);
    }
    cout << hp.res();
    return 0;
}