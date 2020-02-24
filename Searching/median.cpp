#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool check(int mid, std::vector<int> v, int k)
{
	int operations = 0;
	int n = v.size();
	for (int i=n/2;i<n;i++)
	{
		if (v[i] < mid)
			operations += mid - v[i];
		else
			break;
		if (operations > k)
			break;
	}

	if (operations > k)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int n,k;
 	cin >> n >> k;

 	std::vector<int> v;

 	for (int i=0;i<n;i++)
 	{
 		int x;
 		cin >> x;
 		v.pb(x);
 	}

 	sort(v.begin(),v.end());
 	int left = 1, right = 2000000000, mid;

 	while (left < right)
 	{
 		mid = (left + right + 1) / 2;

 		if (check(mid,v,k))
 			left = mid;
 		else
 			right = mid-1;
 	}

 	cout << left << endl;

	return 0;
}