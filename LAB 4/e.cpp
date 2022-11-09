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

int height(node *root){
    if(not root)return 0;
    int l = height(root->left), r = height(root->right);
    return 1 + max(l, r);
}

int widthOfBinaryTree(node* root, int lvl) {
        if(root == NULL)
            return 0;
        if(lvl == 1)return 1;

        return widthOfBinaryTree(root->left, lvl-1) + widthOfBinaryTree(root->right, lvl-1);
}
        
int getMax(node *root){
    int mx = 0;
    for(int i = 1; i <= height(root); i++){
        mx = max(mx, widthOfBinaryTree(root, i));
    }

    return mx;
}

node *insert(node *root, int x, int y, int z){
    if(not root){
        root = new node(y);
        return root;
    }
    if(root->val == x){
        if(z == 0){
            root->left = insert(root->left, x, y, z);
        }else{
            root->right = insert(root->right, x, y, z);
        }
    }

    insert(root->left, x, y, z);
    insert(root->right, x, y, z);

    return root;
}

int main(){
    int n;cin >> n;
    n--;
    node *root = new node(1);
    while(n--){
        int x, y, z;
        cin >> x >> y >> z;
        root = insert(root, x, y, z);
    }

    cout << getMax(root);

}