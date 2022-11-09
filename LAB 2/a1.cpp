#include <iostream>
#include <cmath>
using namespace std;

struct NODE
{
    int val;
    NODE * next;
    NODE(int x){
        val = x;
        next = NULL;
    }
};


struct LL
{
    NODE * head;
    NODE * tail;
    LL(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        NODE * n = new NODE(x);
        if(head == NULL){
            head = n;
            tail = n; 
        }
        else {
            tail->next = n;
            tail = n;
        }
    }

    void print(){
        NODE * cur = head;
        while (cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;    
        }
    }


    int find_min_ind(int k){
        NODE * cur = head;
        int ind;
        int i = 0;
        int min = 1e9;
        while (cur)
        {
            if(min > abs(k-cur->val)){
                min = abs(k-cur->val);
                ind = i;
            }
            i++;
            cur = cur->next;

            
        }
        return ind;
        
    }
};



int main () {
    LL ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ll.add(x);
    }
    int k;
    cin >> k;
    cout << ll.find_min_ind(k);
    return 0;
}