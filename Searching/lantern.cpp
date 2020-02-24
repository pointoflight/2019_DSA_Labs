#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool check(long double mid, std::vector<int> v, int l)
{
	if (v[0] - 0 >  mid)
		return false;
	if (l - v[v.size()-1] >  mid)
		return false;

	for (int i=0;i<v.size()-1;i++)
	{
		if (v[i+1] - v[i] > 2*mid)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n,l;
    cin >> n >> l;

    std::vector<int> v;

    for (int i=0;i<n;i++)
    {
    	int x;
    	cin >> x;
    	v.pb(x);
    }
    sort(v.begin(), v.end());
    long double left=0,right=l,mid;

    while (left < right - 0.000000001)
    {
    	mid = (left + right)/2;

    	if (check(mid,v,l))
    		right = mid;
    	else
    		left = mid;
    }

    cout << setprecision(20) << mid << endl;

	return 0;
}