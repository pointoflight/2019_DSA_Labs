#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
struct Node{

	int data;
	Node *next;
	Node (int x)
	{
		data = x;
		next = NULL;
	}
};

void printl(Node *head)
{
	while (head != NULL)
	{
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n,x;
    cin >> n >> x;

    Node *head = NULL, *tail= NULL;

    for (int i=0;i<n;i++)
    {
    	int x1;
    	cin >> x1;
    	Node *temp = new Node(x1);

    	if (head == NULL)
    	{
    		head = temp;
    		tail = temp;
    		head -> next = NULL;
    	}
    	else
    	{
    		tail -> next =temp;
    		temp -> next = NULL;
    		tail = temp;
    	}
    }

    Node *in = new Node (x);

    Node *cur = head,*prev = NULL;

    while (cur != NULL && cur -> data < x)
    {
    	prev = cur;
    	cur = cur -> next;
    }

    if (cur == NULL)
    {
    	prev -> next = in;
    	in -> next = NULL;
    }
    else
    {	
    	if (cur == head)
    	{
    		in -> next = head;
    		head = in;
    	}
    	else
    	{
    		in -> next = cur -> next;
    		cur -> next = in;
    	}	
    }

    printl(head);
	return 0;
}