#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        prev = next = NULL;
    }
    void print(){
        cout << val << endl;
    }
};

struct ll{
    node * head;
    node * tail;
    ll(){
       head = NULL; 
       tail = NULL;
    }
    void add_to(int x){
        node * n = new node(x);
        if(head == NULL){
            head = tail = n;
        }else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void add_pre(int x){
        node * n = new node(x);
        if(head == NULL){
            head = tail = n;
        }else{
            head->prev = n;
            n->next = head;
            head = n;
        }
    }
    void print(){
        node * current = head;
        while(current != NULL){
            cout << current->val << " ";
            current = current->next;
        }
    }
    void rprint(){
        node * current = tail;
        while(current != NULL){
            cout << current->val << " ";
            current = current->prev;
        }
    }
};

int main(){
    ll ll;
    int n, c; cin >> n;
    int flag = 1;
    while (n--)
    {
        cin >> c;
        if(c == 1 && flag == 1){
            int x; cin >> x;
            ll.add_to(x);
        }
        else if(c == 1 && flag == -1){
            int x; cin >> x;
            ll.add_pre(x);
        }
        else flag *= (-1);
    }
    if(flag == 1) ll.print();
    else ll.rprint();
    
    return 0;
}