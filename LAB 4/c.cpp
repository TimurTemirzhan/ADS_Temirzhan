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

node *insert(node*root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(root->val > x){
        root->left = insert(root->left, x);
    }else root->right = insert(root->right, x);

    return root;
}

void find(node *&root, int x){
    while(root){
        if(root->val == x)return;
        else if(root->val > x)root = root->left;
        else root = root->right;
    }
}

void pre(vector<int> &v, node *root){
    if(not root)return;
    v.push_back(root->val);
    pre(v, root->left);
    pre(v, root->right);
}

void sum(vector<int> &v, node *root){
    if(not root)return;
    
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    while(n--){
        int x;cin >> x;
        root = insert(root, x);
    }
    int k;cin >> k;
    vector<int> v;
    find(root, k);
    pre(v, root);
    for(int x:v)cout << x << ' ';
}