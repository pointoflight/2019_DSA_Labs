#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

struct Node{

	int data;
	Node *prev, *next;

	Node (int val)
	{
		data = val;
		prev = NULL;
		next = NULL;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	Node *head = new Node(234);
 	Node *tail = head;

 	Node *temp = new Node(233234);

 	tail -> next = temp;

 	cout << head -> next -> data << endl;

	return 0;
}