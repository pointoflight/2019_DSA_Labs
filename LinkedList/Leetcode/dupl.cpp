// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
    // your code goes here
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        Node *head = NULL;
                Node *temp = head;

        for(int i=0;i<K;i++){
        int data;
        cin>>data;
            if(head==NULL)
            head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }
        Node *result  = removeDuplicates(head);
        print(result);
        cout<<endl;
    }
    return 0;
}// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// root: head node
Node *removeDuplicates(Node *root)
{
 // your code goes here
    
    if (root -> next == nullptr)
    return root;
    
    Node *prev = root;
    Node *cur = root -> next;
    
    while (cur -> next != nullptr)
    {
        if (prev -> data == cur -> data)
        {
            prev -> next = cur -> next;
            cur = cur -> next;
            
        }
        else
        {
            prev = cur;
            cur = cur ->next;
        }
    }
    
    if (prev -> data == cur -> data)
    prev -> next = nullptr;
    
    return root;
}
