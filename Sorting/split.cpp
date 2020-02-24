#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int n,k;
 	cin >> n >> k;   

 	std::vector<int> v(n);

 	for (int i=0;i<n;i++)
 		cin >> v[i];

 	int ans = v[n-1] - v[0];

 	//cout << ans << endl;
 	std::vector<int> d;

 	for (int i=1;i<n;i++)
 		d.pb(v[i-1]-v[i]);

 	sort(d.begin(),d.end());

 	for (int i=0;i<k-1;i++)
 		ans += d[i];
 	//for (int i=0;i<d.size();i++)
 	//	cout << d[i] << " ";
 	//cout << endl;
 	cout << ans << endl;
	return 0;
}