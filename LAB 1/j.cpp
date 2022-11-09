#include <iostream>
#include <deque>

using namespace std;
deque <int> dq;

int main()
{
    char d; 
    int n;
    while(cin >> d)
    {
        if(d == '+'){
            cin >> n;
            dq.push_front(n);
        }
        else if(d == '-'){
            cin >> n;
            dq.push_back(n);
        }
        else if(d == '!'){
            return 0;
        }
        else if (d == '*'){
            if(dq.size() == 0){
                cout << "error" << endl;
            }
            else if(dq.size() == 1){
                cout << dq.front()*2 << endl;
                dq.pop_front();
            }
            else {
                cout << dq.front() + dq.back() << endl;
                dq.pop_back(); dq.pop_front();
            }
        }
    }
}