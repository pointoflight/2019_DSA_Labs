#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool check(long double mid, std::vector<long double> radius, ll f,long double pi)
{
	ll totalpieces = 0;

	for (int i=0;i<radius.size();i++)
	{
		ll pieces = (ll) ((pi * radius[i] * radius[i]) / mid);
		//printf("pieces = %d\n",pieces);
		totalpieces += pieces;
	}
	if (totalpieces >= f)
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
	 	ll f;
	 	cin >> n >> f;
	 	f++;

		std::vector<long double> radius;

		for (int i=0;i<n;i++)
		{
			long double x;
			cin >> x;
			radius.pb(x);
		} 	   

		sort(radius.begin(), radius.end());

		long double pi = 3.14159265358979323846264338327950;
		long double vol = 0;

		for (int i=0;i<n;i++)
			vol += pi * radius[i] * radius[i];

		long double left = 0, right = vol,mid;

		while (left < right - 0.00001)
		{	
			mid = (left + right)/2;
			//printf("%0.6Lf\n",mid);

			if (check(mid,radius,f,pi))
				left = mid;
			else
				right = mid;

		}

		cout << setprecision(20) << mid << endl;
	}

	return 0;
}