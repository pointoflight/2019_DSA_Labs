#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int n;
 	cin >> n;
 	std::vector<int> v;   
 	for (int i=0;i<n;i++)
 	{
 		int x;
 		cin >> x;
 		v.pb(x);
 	}

 	int x;
 	cin >> x;

 	auto lo = lower_bound(v.begin(),v.end(),x);
 	auto hi = upper_bound(v.begin(), v.end(),x);

 	printf("%ld\n",hi-lo);

	return 0;
}