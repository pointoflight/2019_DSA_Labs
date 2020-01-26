// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};

void sortedInsert(struct Node*head_ref, int x);
/* function to insert a new_Node in a list in sorted way.
   Note that this function expects a pointer to head Node
   as this can modify the head of the input linked list */

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int n,x;
  cin >> n >> x;

  
  /* start with empty linked list */
  Node *head = NULL, *tail = NULL;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    
    for (int i=0;i<n;i++)
    {
      int x;
      cin >> x;
      Node *temp = new Node(x);

      if (head == NULL)
      {
        head = temp;
        tail = head;
        head -> next = NULL;
      }
      else
      {
        tail -> next = temp;
        tail = temp;
        temp -> next = NULL;
      }
    }
    sortedInsert(head,x);
    printList(head);

  return 0;
}
// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
void sortedInsert(Node* head_ref, int x)
{
   //Your code here
    Node *cur = head_ref;
    Node *prev = NULL;
    while (cur != NULL && cur -> data < x)
    {
      prev = cur;
      cur = cur -> next;
    }

    if (cur == NULL)
    {
      Node *temp = new Node(x);
      prev -> next = temp;
      temp -> next = NULL;     
      return;
    } 

    Node *temp = new Node(x);
    cur -> next = temp;
    temp -> next = NULL;



}