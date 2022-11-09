#include <iostream>
#include <vector>
#include <queue>

using namespace std;

deque <int> b, n;
int fun(int cnt)
{
    if(b.front() > n.front()){
        if(b.front() == 9 and n.front() == 0){
            n.push_back(b.front());
            n.push_back(n.front());
        }
        else {
            b.push_back(b.front());
            b.push_back(n.front());
        }
    }
    else{
        if(n.front() == 9 and b.front() == 0){
            b.push_back(b.front());
            b.push_back(n.front());
        }
        else{
            n.push_back(b.front());
            n.push_back(n.front());
        }
    }
    b.pop_front();
    n.pop_front();

    if(b.empty()){
        cout << "Nursik " << cnt;
        return 0;
    }
    else if(n.empty()){
        cout << "Boris " << cnt;
        return 0;
    }
    cnt++;
    if(cnt == 1000000){
        cout << "blin nichya" ;
        return 0;
    }
    return fun(cnt);


}
int main ()
{
    int counter = 1;
    int m, d;
    for(int i = 0; i < 5; i++){
        cin >> d;
        b.push_back(d);
    }
    for(int i = 0; i < 5; i++){
        cin >> m;
        n.push_back(m);
    }
    fun(counter);
}