#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
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
    if(x > root->val)root->right = insert(root->right, x);
    else root->left = insert(root->left, x);

    return root;
}

void in(vector<node*> &v, node *root){
    if(root){
        in(v, root->left);
        v.push_back(root);
        in(v, root->right);
    }
}

node *BSTtoBal(vector<node*> &v, int l, int r){
    if(l > r)return NULL;
    int m = (r+l)/2;
    node *root = v[m];

    root->left = BSTtoBal(v, l, m-1);
    root->right = BSTtoBal(v, m+1, r);

    return root;
}

node *newTree(node *root){
    vector<node*> v;
    in(v, root);

    return BSTtoBal(v, 0, v.size()-1);
}

void pre(node *root){
    if(not root)return;
    cout << root->val << ' ';
    pre(root->left);
    pre(root->right);
}



int main(){
    node *root = NULL;
    int n;cin >> n;
    int sz = pow(2, n) -1;
    while(sz--){
        int x;cin >> x;
        root = insert(root, x);
    }

    root = newTree(root);
    pre(root);
}