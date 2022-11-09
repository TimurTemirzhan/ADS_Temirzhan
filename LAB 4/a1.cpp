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
    bool exist(string s){
        return this->exist(root, s);
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
    bool exist(node *current, string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') current = current->left;
            else current = current->right;
            if(current == NULL) return false;
        }
        return true;
    }
};


int main(){

    bst * b = new bst();

    int n, r; cin >> n >> r;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b->add(a[i]);
    }
    string s;
    for(int i = 0; i < r; i++){
        cin >> s;
        string ans = b->exist(s) ? "YES" : "NO";
        cout << ans << endl;
    }

    
    // b->print();

    return 0;
}