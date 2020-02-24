#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool check(int k, std::vector<ll> v, ll d)
{
	ll max = v[k-1];
	ll min = v[v.size()-k];
	printf("k=%d ",k);
	printf("max = %lld min = %lld\n",max,min );
	printf("max-min=%lld\n",max-min);
	if (k-1 == v.size()-k)
	{
		ll min1 = v[k-2];
		ll max1 = v[k];
		if (max1 - min1 >= d)
			return true;
		if (max1 - min1 >= d)
			return true;
	}
	if (max-min >= d)
		return true;

	return false;
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
 		ll d;

 		cin >> n >> d;

 		std::vector<ll> v;

 		for (int i=0;i<n;i++)
 		{
 			ll x;
 			cin >> x;
 			v.pb(x);
 		}
 		sort(v.begin(),v.end());
 		int k=2;
 		for (k=2;k<=n;k++)
 		{
 			if (check(k,v,d))
 				break;
 			// printf("sdf\n");
 			// printf("%d\n",k);
 		}

 		cout << k << endl;
 	}   

	return 0;
}