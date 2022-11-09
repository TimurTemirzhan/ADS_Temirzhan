#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }
    node *search(int k){
        return this->search(k, this->root);
    }
    void ans(int k){
        node *n = search(k);
        print(n);
    }
    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
        }
        return current;
    }
    void print(node * current){
        if(current != NULL){
            cout << current->val << " ";
            print(current->left);
            
            print(current->right);
        }
    }
    node *search(int k, node *cur){
        if(cur == NULL) return 0;
        if(cur->val == k) return cur;
        else if(cur->val>k) return search(k, cur->left);
        else return search(k, cur->right);
    }

};


int main(){

    int n; cin >> n;
    int a[n];

    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        cin >> a[i]; b->add(a[i]);
    }
    int k; cin >> k;
    b->ans(k);

    return 0;
}