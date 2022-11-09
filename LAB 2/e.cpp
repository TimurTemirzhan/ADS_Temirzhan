#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
    Node* tmp1 = head;
    Node *tmp2, *dup;
    while(tmp1 and tmp1->next){
        tmp2 = tmp1;
            if(tmp1->data == tmp2->next->data){
                dup = tmp2->next;
                tmp2->next = tmp2->next->next;
                delete dup;
            }else{
                tmp2 = tmp2->next;
                tmp1 = tmp1->next;
            }

    }
}  

int getCount(Node* head)  
{  
    int count = 0; 
    while(head){head = head->next;count++;}

    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}