#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool compare(pair<int,int>a,pair<int,int>b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
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

	 	std::vector<pair<int,int> > v;   
	 	for (int i=0;i<n;i++)
	 	{
	 		int x,y;
	 		cin >> x >> y;
	 		v.pb(mp(x,y));
	 	}

	 	sort(v.begin(),v.end(),compare);
	 	// for (int i=0;i<v.size();i++)
	 	// 	printf("%d %d\n",v[i].first,v[i].second);

	 	std::vector<pair<int,int> > ans;

	 	for (int i=0;i<n;)
	 	{
	 		int max=v[i].second,min=v[i].first;
	 		int j =  i+1;
	 		while (j < n)
	 		{
	 			if (max >= v[j].first)
	 			{
	 				if (max < v[j].second)
	 					max = v[j].second;
	 				j++;
	 				continue;
	 			}
	 			else
	 				break;
	 		}
	 		// join all from i to j-1
	 		ans.pb(mp(min, max));
	 		i = j;
	 	}

	 	for (int i=0;i<ans.size();i++)
	 		printf("%d %d ",ans[i].first, ans[i].second);
	 	printf("\n");
	}
	return 0;
}