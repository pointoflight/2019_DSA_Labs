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

 		int i=1;

 		while (i < k)
 		{
 			while (!dq.empty() && v[dq.back()] <= v[i])
 				dq.pop_back();
 			dq.push_back(i);
 			i++;
 		}

 		cout << v[dq.front()] << " ";

 		while (i < n)
 		{
 			while (!dq.empty() && v[dq.back()] <= v[i])
 				dq.pop_back();
 			dq.push_back(i);
 			while (i - dq.front() >= k)
 				dq.pop_front();
 		// 	 printf("dq;\n");
 		// deque <int> dq1 = dq;
 		// while (!dq1.empty())
 		// {
 		// 	printf("%d ", v[dq1.front()]);
 		// 	dq1.pop_front();
 		// }
 		// printf("\n");
 			cout << v[dq.front()] << " ";
 			i++;
 		}
 		cout << endl;
 	}    

	return 0;
}