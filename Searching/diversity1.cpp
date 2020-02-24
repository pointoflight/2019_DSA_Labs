#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool check(int mid, std::vector<ll> v, ll d)
{
	int size = mid;
	int point1=0,point2=size-1;

	ll min = v[point2] - v[point1];

	while (point2 < v.size())
	{
		if (min > v[point2] - v[point1])
			min = v[point2] - v[point1];
		point1++;
		point2++;
	}

	if (min >= d)
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
 		int n,d;
 		cin >> n >> d;

 		std::vector<ll> v;

 		for (int i=0;i<n;i++)
 		{
 			ll x;
 			cin >> x;
 			v.pb(x);
 		}

 		sort(v.begin(), v.end());

 		int left = 2, right = n, mid;

 		while (left < right)
 		{
 			mid = (left + right)/2;

 			if (check(mid,v,d))
 				right = mid;
 			else left = mid + 1;
 		}

 		cout << left << endl;

 	}   

	return 0;
}