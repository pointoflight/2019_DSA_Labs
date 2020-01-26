#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

struct Node
{
	int data;
	Node *next, *prev;
	Node (int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};

void insert(int val, Node *head, Node *tail)
{
	Node *temp = new Node(val);

	if (head == NULL)
	{
		head = temp;
		tail = temp;
		head -> next = head;
		head -> prev = head;
		return;
	}

	tail -> next = temp;
	temp -> prev = tail;
	temp -> next = head;
	head -> prev = temp;
	tail = temp;
	return;

}
void printl(Node *head, int size)
{
	for (int i=0;i<size;i++)
	{
		cout << head -> data << " ";
		head = head -> next;
	}
	printf("\n");
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

	int n;
	cin >> n;

	Node *head = NULL, *tail = NULL;
	
	int size = 0;
	
	for (int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		Node *temp = new Node(x);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			tail -> next = tail;
			tail -> prev = head;
		}
		else
		{
			tail -> next = temp;
			temp -> prev = tail;
			temp -> next = head;
			head -> prev = temp;
			tail = temp;
		}

		size++;
	}

	head -> next -> prev = tail;
	printl(head,size);
	tail -> prev -> next = head;
	printl(head,size);
	tail -> next = head -> next;
	printl(head,size);
	head -> next = tail;
	printl(head,size);
	head -> prev = tail -> prev;
	printl(head,size);
	tail -> prev = head;
	printl(head,size);
	


	cout << endl;


	return 0;
}