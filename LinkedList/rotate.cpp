#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
struct Node {

	int data;
	Node *prev,*next;

	Node (int x)
	{
		data = x;
		prev = NULL;
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
 		int n,p;
 		cin >> n >> p;
 		
 		p = p%n;

 		printf("n = %d\n",n);
 		printf("p = %d\n",p);
 		printf("p mod n = %d\n",p%n);
 		Node *head = NULL, *tail =NULL;

 		for (int i=0;i<n;i++)
 		{
 			int x;
 			cin >> x;
 			Node *temp = new Node (x);

 			if (head ==NULL)
 			{
 				head = temp;
 				tail = temp;
 				head -> next = NULL;
 				head -> prev = NULL;
 			}
 			else
 			{
 				tail -> next = temp;
 				temp -> prev = tail;
 				temp -> next = NULL;
 				tail = temp;
 			}
 		}

 		if (n==1 || p ==0)
 			{
 				printl(head);
 				return 0;
 			}
 		Node *originalhead = head;
 		Node *cur = head;
 		int c = 0;
 		while (c < p)
 		{
 			c++;
 			cur = cur -> next;
 		}

 		Node *newtail = cur -> prev;

 		head = cur;
 		head -> prev -> next = NULL;
 		head -> prev = NULL;

 		while (cur -> next != NULL)
 			cur = cur -> next;

 		cur -> next = originalhead;
 		originalhead -> prev = cur;
 		tail = newtail;

 		cur = head;

 		while (cur != NULL)
 		{
 			cout << cur -> data << " ";
 			cur = cur -> next;
 		}

 		cout << endl; 
 	

	return 0;
}