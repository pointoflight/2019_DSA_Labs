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

int isPrime(int n)
{
	int yes = 1;

	if (n==1 || n==0)
		return 0;

	for (int i=2;i*i<=n;i++)
	{
		if (n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n;
    cin >> n;
    Node *head = NULL,*tail = NULL;
    int size = n;

    for (int i=0;i<n;i++)
    {
    	int x;
    	cin >> x;
    	Node *temp = new Node(x);

    	if (head == NULL)
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

    Node *cur = head;

    for (int i=0;i<n;i++)
    {
    	if (isPrime(cur -> data))
    	{	
    		if (size == 1)
    		{
    			size = 0;
    			break;
    		}
    		else
    		{
    			if (cur == head)
    			{
    				head = head -> next;
    				head -> prev = NULL;
    			}
    			else if (cur == tail)
    			{
    				tail = tail -> prev;
    				tail -> next = NULL;
    			}
    			else
    			{
    				cur -> prev -> next = cur -> next;
    				cur -> next -> prev = cur -> prev;
    			}
    			size--;
    		}
    	}	
    	cur = cur -> next;
    }

    if (size == 0)
    {
    	printf("empty\n");
    	return 0;
    }
    cur = head;

    for (int i=0;i<size;i++)
    {
    	cout << cur -> data << " ";
    	cur = cur -> next;
    }

    return 0;

	return 0;
}