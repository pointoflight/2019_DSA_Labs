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
    	int n;
    	cin >> n;
    	std::vector<int> v(n);

    	for (int i=0;i<n;i++)
    		cin >> v[i];

    	sort(v.begin(),v.end());

    	int i = n;

    	ll ans = 0;
    	while (i > 3)
    	{
    		ans += min(v[0]+2*v[1]+v[i-1],2*v[0] + v[i-1] + v[i-2]);
    		i -= 2;
    	}

    	if (i==3)
    		ans += v[0] + v[1] + v[2];
    	else if (i==2)
    		ans += v[1];
    	else if (i==1)
    		ans += v[0];

    	cout << ans << endl;
    }

	return 0;
}