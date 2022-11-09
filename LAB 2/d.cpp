#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> v;
struct node
{
    int val;
    node *next;
    node(int x){
        val = x;
        next = NULL;
    }
};

int mode(int n, node *head)
{
    int a[1001] = {0};
    int cnt = 1;
    int max = -1e9;
    node *current = head;
    while(current)
    {
        a[current->val] += 1;
        current = current->next;
    }
    for(int i = 0; i < 1001; i++) if(a[i]>max) max = a[i];
    for(int i = 0; i < 1001; i++) if(a[i] == max) v.push_back(i);
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
} 
int main()
{
    int n; cin >> n;
    node *head, *tail;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        node *cur = new node(x);
        if(i == 0) head = tail = cur;
        else{ 
            tail->next = cur;
            tail = cur;
        }
    }
    mode(n, head);
    return 0;
}