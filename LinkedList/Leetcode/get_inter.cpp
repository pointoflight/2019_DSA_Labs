// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here

    Node *cur1 = head1;
    Node *cur2 = head2;

    int length1 = 0, length2 = 0;

    while (cur1 != nullptr)
    {
        length1++;
        cur1 = cur1 -> next;
    }
    while (cur2 != nullptr)
    {
        length2++;
        cur2 = cur2 -> next;
    }

    int diff = abs(length1 - length2);

    Node *cur;

    if (length1 > length2)
        cur = head1;
    else
        cur = head2;

    int c = 0;

    while (c < diff)
    {
        cur = cur -> next;
        c++;
    }

    Node *othercur;
    if (length1 > length2)
        othercur = head2;
    else
        othercur = head1;

    while (cur != nullptr && othercur != nullptr)
    {
        if (cur -> data == othercur -> data && cur -> next == othercur -> next)
            return cur ->data;
            cur = cur -> next;
            othercur = othercur -> next;
    }

    return -1;

}
