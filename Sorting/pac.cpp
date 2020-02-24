#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool compare(pair<int,int> a, pair<int,int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
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
 		int curx = 0, cury = 0;
 		string s;
 		bool candoall = true;

 		for (int i=0;i<n;i++)
 		{
 			int x = v[i].first, y = v[i].second;
 			if (curx > x || cury > y)
 			{
 				candoall = false;
 				break;
 			}	

 			for (int j=0;j<x-curx;j++)
 				s.append("R");
 			for (int j=0;j<y-cury;j++)
 				s.append("U");
 			curx = x;
 			cury = y;
 		}
 		if (candoall)
 			{
 				cout << "YES" << endl;
 				cout << s;
 			}
 		else
 			cout << "NO";
 		cout << endl;
 	}   

	return 0;
}