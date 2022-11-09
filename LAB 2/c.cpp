#include <iostream>
using namespace std;

struct NODE
{
    int val, ind;
    NODE* next;
    NODE(int x, int i){
        val = x;
        ind = i;
        next = NULL;
    }
};

void FindEvenInd(int n, NODE *head)
{
    NODE *cur = head;
    for(int i = 0; i < n; i++){
        if(cur->ind%2==0)cout << cur->val << " ";
        cur = cur->next;
    }
}


int main()
{
    int n; cin >> n;
    NODE *head, *tail;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        NODE *cur = new NODE(x, i);

        if(i == 0) head = tail = cur;
        else{
            tail->next = cur;
            tail = cur;
        }
    }
    FindEvenInd(n, head);
    return 0;
}