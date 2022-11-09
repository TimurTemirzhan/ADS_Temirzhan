#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
int mx = 0;
class BST{ 
private: 
    node * root; 
    node * push(node *cur, int val){ 
        if(cur == NULL) return new node(val); 
        if(val > cur->val) cur->right = push(cur->right, val); 
        if(val < cur->val) cur->left = push(cur->left, val); 
        return cur; 
    } 
 
    int height(node * cur){ 
        if(cur == NULL) return 0; 
        return 1 + max(height(cur->left), height(cur->right)); 
    } 
 
    void find(node * cur){ 
        if(cur != NULL){ 
            if(height(cur->left)+height(cur->right)+1 > mx ) mx = height(cur->left)+height(cur->right)+1;  
            find(cur->left); 
            find(cur->right); 
        } 
    } 
 
 
 
public: 
    BST(){ 
        root = NULL; 
    } 
 
    void push(int val){ 
        root = push(root, val); 
    } 
    void find(){ 
        find(root); 
    } 
}; 
 
 
 
int main(){ 
    BST tree; 
    int n, x; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        int t; 
        cin >> t; 
        tree.push(t); 
    } 
    tree.find(); 
    cout << mx; 
    return 0; 
}