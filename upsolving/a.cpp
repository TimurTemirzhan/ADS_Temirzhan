#include <bits/stdc++.h>
using namespace std;

const int  N = 1e3 + 5;
int arr[N];

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val = val;
        this->left = this-> right = NULL;
    }
};

struct BST{
    public:
    Node * root;
    BST(){
        root = NULL;
    }
    void add(int x){
        Node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }
    void findCnt(Node * current, int k){
        Node * l = current;
        Node * r = current;
        while(l -> left && r->right){
            k++;
            arr[k]++;
            l = l->left;
            r = r->right;
        }
    }
    void traverse(Node * currrent){
        if(currrent == NULL){
            return ;
        }
        findCnt(currrent, 1);
        traverse(currrent->left);
        traverse(currrent->right);
    }
    private:
    Node * add(Node * current, int x){
        if(current == NULL){
            current = new Node(x);
        }
        else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }
            else{
                add(current->left, x);
            }
        }
        else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }
            else {
                add(current->right, x);
            }
        }
        return current;
    }
    void print(Node * current){
        if(current != NULL){
            print(current->left);
            cout<<current->val<<" ";
            print(current->right);
        }
    }
};

int main(){
    BST * b = new BST();
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        b->add(x);
    }
    //b->print();
    for(int i = 2; i <= n; i++){
        arr[i] = 0;
    }
    b->traverse(b->root);
    for(int i = 2; i <= n; i++){
        cout<<arr[i]<<" ";
    }
}