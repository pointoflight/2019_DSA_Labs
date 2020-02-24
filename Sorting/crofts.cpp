#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first + a.second > b.first + b.second;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int t;
 	cin >> t;
 	while (t--)
 	{
 		int n;
 		cin >> n;

 		vector<pair<int,int> > v;
 		int a[n],b[n];

 		for (int i=0;i<n;i++)
 		{
 			cin >> a[i];
 		}
 		for (int i=0;i<n;i++)
 		{
	 		cin >> b[i];
 		}

 		for (int i=0;i<n;i++)
 		{
 			v.pb(mp(a[i],b[i]));
 		}

 		sort (v.begin(),v.end(),compare);

 		for (int i=0;i<n;i++)
 		{
 			//printf("%d %d\n",v[i].first,v[i].second );
 		}
 		int p1=0,p2=n-1;

 		int alice = 0, bob = 0;

 		int current = 0;

 		for (int i=0;i<n;i++)
 		{
 			if (current % 2 == 0)
 				{
 					alice += v[p1].first;
 					p1++;
 				}
 			else
 				{
 					bob += v[p1].second;
 					p1++;
 				}
 			current++;
 			//printf("alice = %d bob = %d\n",alice, bob );
 		}

 		//printf("alice = %d bob = %d\n",alice, bob );

 		if (alice > bob)
 			printf("First\n");
 		else if (alice < bob)
 			printf("Second\n");
 		else
 			printf("Tie\n");
 	}   

	return 0;
}