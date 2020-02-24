#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
ll merge(std::vector<ll> &v, ll lo, ll hi)
{
	ll res = 0, mid = (lo + hi)/2;
	std::vector<ll> v1,v2;

	for (ll i=lo;i<=mid;i++)
		v1.pb(v[i]);
	for (ll i=mid+1;i<=hi;i++)
		v2.pb(v[i]);

	ll p1=0,p2=0,i=lo;

	while (p1 < v1.size() && p2 < v2.size())
	{
		if (v1[p1] <= v2[p2])
		{
			v[i] = v1[p1];
			p1++;
		}
		else
		{
			v[i] = v2[p2];
			p2++;
			res += v1.size() - p1;
		}
		i++;
	}

	while (p1 < v1.size())
	{
		v[i] = v1[p1];
		i++;
		p1++;
	}

	while (p2 < v2.size())
	{
		v[i] = v2[p2];
		i++;
		p2++;
	}

	return res;

}
ll mergesort(std::vector<ll> &v, ll lo, ll hi)
{
	if (lo == hi)
		return 0;

	ll mid = (lo + hi) / 2;

	ll res = 0,res1,res2,res3;

	res1 = mergesort(v,lo,mid);
	res2 = mergesort(v,mid+1,hi);

	res3 = merge(v,lo,hi);

	//prllf("r1=%d r2=%d r3=%d\n",res1,res2,res3);
	res += res1 + res2 + res3;

	return res;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	ll t;
 	cin >> t;
 	while (t--)
 	{
 		ll n;
 		cin >> n;
 		std::vector<ll> v(n);

 		for (ll i=0;i<n;i++)
 			cin >> v[i];

 		ll ans = mergesort(v,0,n-1);

 		cout << ans << endl;
 	}   

	return 0;
}