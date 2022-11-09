# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
// struct Node {
//   int val;
//   int index;
//   Node *next;
 
//   Node(int x , int i) {
//     index = i;
//     val = x;
//     next = NULL;
//   }
 
// };
 
 
 
int findMaxSum(int n, Node *head) {
    int sum = 0;
    int max = -100000000;
    Node* cur = head;
    for(int i = 0; i < n; i++){
        sum += cur->val;
        if(sum > max) max = sum;
        if(sum<0)sum = 0;
        cur = cur->next;
    }
    return max;

 
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}