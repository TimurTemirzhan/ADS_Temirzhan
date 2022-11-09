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
    if(root->val < x)root->right = insert(root->right, x);
    else root->left = insert(root->left, x);

    return root;
}

int h(node *root){
    if(not root)return 0;
    return 1 + max(h(root->left), h(root->right));
}

void sum(vector<int> &v, node *root, int level){
    if(not root)return;

    v[level] += root->val;

    sum(v, root->left, level+1);
    sum(v, root->right, level+1);
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    for(int i  =0; i < n; i++){
        int x;cin >> x;
        root = insert(root, x);
    }

    vector<int> v;
    for(int i = 0; i < h(root); i++)v.push_back(0);
    sum(v, root, 0);

    cout << v.size()<< endl;
    for(int x:v)cout << x << ' ';
}