#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool compare(string a,string b)
{
	if (a.size() != b.size())
		return a.size() > b.size();
	else
	{
		for (int i=0;i<a.size();i++)
		{
			int c1=int(a[i]),c2=int(b[i]);
			if (c1 != c2)
				return c1 > c2;
		}
	}
	return 0;
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
    	std::vector<string> v(n);

    	for (int i=0;i<n;i++)
    		cin >> v[i];

    	sort(v.begin(),v.end(),compare);

    	for (int i=0;i<n;i++)
    		cout << v[i] << " ";
    	cout << endl;
    }


	return 0;
}