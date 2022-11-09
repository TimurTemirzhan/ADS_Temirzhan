#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(x > root->val){
        root->right = insert(root->right, x);
    }else{
        root->left = insert(root->left, x);
    }

    return root;

}

int size(node *head){
    node *root = head;
    if(not root)return 0;
    return 1 + size(root->left) + size(root->right);
}

int solve(node *root, int x){
    if(root->val == x)return size(root);
    else if(root->val > x)return solve(root->left, x);
    else return solve(root->right, x);
    // return -1;
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        root = insert(root, x);
    }
    int x;cin >> x;
    cout << solve(root, x);
}