#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
struct Node{

	int data;
	Node *next, *prev;
	Node (int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};
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
    		tail = head;
    		head -> next = head;
    		head -> prev = head;
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

    Node *cur = head;
    //cout << cur -> next -> data << endl;
    for (int i=0;i<n;i++)
    {	
    	//printf("cur -> data = %d ",cur -> data);
    	//printf("prev = %d ",cur -> prev -> data );
    	//printf("next = %d\n",cur -> next -> data );
    	if (cur -> data % 2 ==0)
    	{	
    		cur -> prev -> next = cur -> next;
    		cur -> next -> prev = cur -> prev;
    		size--;
    		if (cur == head)
    			head = head -> next;
    		if (cur == tail)
    			tail = tail -> prev;
    	}
    	cur = cur -> next;
    }

    if (size == 0)
    	{
    		cout << "empty" << endl;
    		return 0;
    	}
    cur = head;
    for (int i=0;i<size;i++)
    {
    	cout << cur -> data << " ";
    	cur = cur -> next;
    }

	return 0;
}	