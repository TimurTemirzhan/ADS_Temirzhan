#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val =x;
        left = NULL;
        right = NULL;
    }
};
int sum = 0;

    node *insert(node *cur, int x){
        if(not cur){
            cur = new node(x);
            return cur;
        }
        if(x > cur->val)cur->right = insert(cur->right, x);
        else cur->left = insert(cur->left, x);

        return cur;
    }
    void greaterSum(node *&cur){
        if(cur){
            if(cur->right)greaterSum(cur->right);
            sum += cur->val;
            cur->val = sum;
            if(cur->left)greaterSum(cur->left);
        }
        return;
    }

    void in(node *cur, vector<int> &v){
        if(not cur)return;
        in(cur->right, v);
        v.push_back(cur->val);
        in(cur->left, v);
    }




int main(){
    node *root = NULL;
    int n;cin >> n;
    while(n--){
        int x;cin >> x;
        root = insert(root, x);
    }
    vector<int>v;
    greaterSum(root);
    in(root, v);
    for(int x:v)cout << x << ' ';
}