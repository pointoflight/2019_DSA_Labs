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

void sortedInsert(struct Node**head_ref, int x);
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
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    sortedInsert(&start,x);
   // printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
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
void sortedInsert(Node** head_ref, int x)
{
    Node *head = (*head_ref);
    int size = 0;
    
    Node *cur = head;
    Node *tail;
    while (cur != head || size == 0)
    {
        tail = cur;
        cur = cur -> next;
        size++;
    }

   //cout << size << endl;
   
   cur = head;
   
   Node *prev = NULL;
   
   int c= 0;
   
   while (c < size && cur -> data < x)
   {
        c++;
        prev = cur;
        cur = cur -> next;
   }
   
   Node *newn = new Node(x); 
    
   if (c == size)
   {
      prev -> next = newn;
      newn -> next = head;
      (*head_ref) = head;
      return;
   }
   
   if (prev == NULL)
   {
       newn -> next = head;
       head = newn;
       tail -> next = head;
       (*head_ref) = head;
       return;
   }
   
   newn -> next = prev -> next;
   prev -> next = newn;
   (*head_ref) = head;
    return;

}