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

struct BST{
node *root;

BST(){
    root = NULL;
}
node *insert(node *root, int x){
    if(not root){
        root = new node(x);
        return root;
    }
    if(x > root->val)root->right = insert(root->right, x);
    else root->left = insert(root->left, x);

    return root;
}

bool check(node *root, string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'L'){
            if(not root->left)break;
            else root = root->left;
        }else if(s[i] == 'R'){
            if(not root->right)break;
            else root = root->right;
        }
        cnt++;
    }

    if(cnt == s.size())return true;
    return false;
}
};

int main(){
    BST bst;
    int n, m;
    // node *root = NULL;
    cin >> n >> m;
    while(n--){
        int x;cin >> x;
        bst.root = bst.insert(bst.root, x);
    }
    while(m--){
        string s;
        cin >> s;
        cout << (bst.check(bst.root, s) ? "YES\n" : "NO\n");
    }
}