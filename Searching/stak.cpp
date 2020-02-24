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
    	std::vector<int> v;

    	for (int i=0;i<n;i++)
    	{
    		int x;
    		cin >> x;
    		v.pb(x);
    	}

    	std::vector<int> top;

    	top.pb(v[0]);

    	for (int i=1;i<n;i++)
    	{
    		// add v[i] to stacks;
    		if (v[i] >= top[top.size()-1])
    			top.pb(v[i]);
    		else
    		{
    			// binary search for where to put v[i]
    			int pos = upper_bound(top.begin(),top.end(),v[i]) - top.begin();
    			top[pos] = v[i];
    		}
    	}

    	printf("%d ",top.size());
    	for (int i=0;i<top.size();i++)
    		printf("%d ",top[i]);
    	printf("\n");
    }	

	return 0;
}