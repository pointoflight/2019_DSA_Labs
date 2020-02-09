#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

	stack<int> s;

	int min = 1000000000; 		
	
	while (true)
	{
		int x,y;
		cin >> x;

		if (x==-1)
			break;
		if (x==0)
		{
			cin >> y;

			if (s.empty())
			{
				s.push(y);
				min = y;
				continue;
			}

			if (y < min)
			{
				s.push(2*y - min);
				min = y;
			}
			else 
				s.push(y);

			continue;
		}

		if (x==1 && !s.empty())
		{
			if (s.top() < min)
			{
				min = 2*min - s.top();
			}
			s.pop();
			continue;
		}

		if (x==2 && !s.empty())
		{
			printf("%d\n",min);
			continue;
		}

		if (s.empty())
			printf("stack is empty\n");

	}
 
	return 0;
}