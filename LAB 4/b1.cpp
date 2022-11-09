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

    int check(int k){
        return this->check(root,k);
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
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }
    int get_size(node *cur){
        if(cur == NULL) return 0;
        return get_size(cur->left) + get_size(cur->right) +1;

    }
    int check(node *cur, int k){
        if(cur == NULL) return -1;
        else if(cur->val == k) return get_size(cur);
        if(cur->val > k) return check(cur->left, k);
        else return check(cur->right, k);
    }
};


int main(){

    int n, f; cin >> n;
    int a[n];

    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        b->add(a[i]);
    }
    cin >> f;
    cout << b->check(f);


    // b->print();

    return 0;
}