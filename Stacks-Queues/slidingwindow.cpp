#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int t;
 	cin >> t;
 	while (t--)
 	{
 		int n,k;
 		cin >> n >> k;

 		std::vector<int> v;
 		for (int i=0;i<n;i++)
 		{
 			int x;
 			cin >> x;
 			v.pb(x);
 		}

 		deque <int> dq;

 		dq.push_back(0);
	 	int i = 1;

 		while (i < k)
 		{
 			while (!dq.empty() && v[dq.back()] <= v[i])
 				dq.pop_back();
 			dq.push_back(i);
 			i++;	
 		}
 		// printf("dq;\n");
 		deque <int> dq1 = dq;
 		// while (!dq1.empty())
 		// {
 		// 	printf("%d ", dq1.front());
 		// 	dq1.pop_front();
 		// }
 		// printf("\n");
 		//cout << v[dq.front()] << " ";

 		int c = 0;
 		while (i < n)
 		{
 			if (c == k)
 			{	
 				while (!dq.empty() && v[dq.back()] <= v[i])
 					dq.pop_back();
 				dq.push_back(i);

 				while (!dq.empty() && i - dq.front() >= k)
 					dq.pop_front();
 				cout << " ans " << v[dq.front()] << " ";
 				c = 0;
 			}	
 			while (!dq.empty() && v[dq.back()] <= v[i])
 				dq.pop_back();
 			dq.push_back(i);
 			printf("c = %d\n",c );
 			printf("\ndq;\n");
 		dq1 = dq;
 		while (!dq1.empty())
 		{
 			printf("%d ", dq1.front());
 			dq1.pop_front();
 		}
 		printf("\n");
 			c++;
 			i++;
 		}
 		printf("\n");
 	}   

	return 0;
}