#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int val;
    int count;
    struct node *left, *right;
};
 
struct node *newNode(int item)
{
    struct node *temp = new node();
    temp->val = item;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}
 
bool find(node *current, int x){
	if(current == NULL)
		return false;
	
	if(x > current->val) return find(current->right, x);
	else if(x < current->val) return find(current->left, x);
	return true;
} 


void inorder(struct node *root, int x)
{
    if (root != NULL)
    {
        if(x == root->val){
            cout << root->count << endl;
            return;
        }
        inorder(root->left, x);
        
        inorder(root->right, x);
    }
}
 
struct node* insert(struct node* node, int val)
{
    if (node == NULL) return newNode(val);
 
    if (val == node->val)
    {
    (node->count)++;
        return node;
    }
 
    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);
 
    return node;
}
 
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct node* deleteNode(struct node* root,
                                 int val)
{
    if (root == NULL) return root;
 
    if (val < root->val)
        root->left = deleteNode(root->left, val);
 
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
 
    else
    {
        if (root->count > 1)
        {
            (root->count)--;
            return root;
        }
 
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->val = temp->val;
        root->count = temp->count;
       
          temp->count = 0;
 
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main(){
    node* root = NULL;
    int n;cin >> n;
    while(n--){
        string s;cin >> s;
        if(s == "insert"){
            int x; cin >> x;
            root = insert(root, x);
        }else if(s == "delete"){
            int x;cin >> x;
            root = deleteNode(root, x);
        }
        else if(s == "cnt"){
            int x;cin >> x;
            if(find(root, x))
                inorder(root, x);
            else cout << 0 << endl;
        }
    }


}