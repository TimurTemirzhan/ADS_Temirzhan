#include <iostream>

using namespace std;


struct node{
    string val;
    node *next, *prev;
    node(string x){
        val = x;
        next = prev = NULL;
    }
};


struct dll
{
    node * head;
    node * tail;
    dll(){
        head = tail = NULL;
    }
    void add(string x){
        node * n = new node(x);
        if (head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }


    void print(int n){
        node * cur = head;
        while (n--)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }


    void solve(int k){
        node * cur = head;
        while (k--)
        {
            cur = cur->next;
        }
        tail->next = head;
        head = cur;
    }



};


int main (){
    int n, m;
    cin >> n >> m;
    dll _dll;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        _dll.add(s);
    }

    _dll.solve(m);
    _dll.print(n);



    return 0;
}
