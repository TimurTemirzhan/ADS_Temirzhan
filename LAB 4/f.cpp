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
    if(x > root->val){
        root->right = insert(root->right, x);
    }else root->left = insert(root->left, x);

    return root;
}

int cnt = 0;
void tri(node *root){
    if(not root)return;
    if(root->right and root->left)cnt++;
    tri(root->left);
    tri(root->right);
}

int main(){
    int n;cin >> n;
    node *root = NULL;
    while(n--){
        int x; cin >> x;
        root = insert(root, x);
    }
    tri(root);

    cout << cnt;
}