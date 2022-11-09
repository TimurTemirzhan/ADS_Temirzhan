#include <iostream>
using namespace std;

struct NODE
{
    string word;
    NODE * next;
    NODE(string x){
        word = x;
        next = NULL;
    }
};

struct LL
{
    NODE* head;
    NODE* tail;
    LL(){
        head = NULL;
        tail = NULL;
    }
    void add(string s){
        NODE * n = new NODE(s);
        if(head == NULL){
            tail = n;
            head = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
    }
    void print(){
        NODE* current = head;
        while(current != NULL){
            cout << current->word << " ";
            current = current->next;
        }
    }
    void shift(int n, int k){
        LL ans;
        NODE* current = head;
        int i = 0;
        while(current){
            if(i>=k){ 
                ans.add(current->word);  
            }
            current = current->next;
            i++;
        }
        NODE* current1 = head;
        for(int j = 0; j < k; j++){
            ans.add(current1->word);
            current1 = current1->next;
        }
        ans.print();
    }
};

int main()
{
    int n, k; cin >> n >> k;
    LL ll;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ll.add(s);
    }
    ll.shift(n,k);
    return 0;
}