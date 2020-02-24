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
 		int n,m,q;
 		cin >> n >> m >> q;
 		
 		int vert[100001], hor[100001];

 		for (int i=0;i<100001;i++)
 		{
 			vert[i] = 0;
 			hor[i] = 0;
 		}

 		vert[1] = 1;
 		hor[1] = 1;
 		vert[m] = 1;
 		hor[n] = 1;

 		for (int i=0;i<q;i++)
 		{
 			int x,y;
 			cin >> x >> y;
 			hor[x] = 1;
 			vert[y] = 1;
 		}

 		std::vector<int> v;
 		std::vector<int> h;

 		for (int i=0;i<100001;i++)
 		{
 			if (vert[i] == 1)
 				v.pb(i);
 			if (hor[i] == 1)
 				h.pb(i);
 		}

 		int rows = h.size();
 		int col = v.size();

 		int maxv = 0,minv = 1000000;
 		for (int i=1;i<v.size();i++)
 		{
 			if (maxv < v[i] - v[i-1])
 				maxv = v[i] - v[i-1];
 			if (minv > v[i] - v[i-1])
 				minv = v[i] - v[i-1];
 		}

 		int maxh = 0, minh = 1000000;
 		for (int i=1;i<h.size();i++)
 		{
 			if (maxh < h[i] - h[i-1])
 				maxh = h[i] - h[i-1];
 			if (minh > h[i] - h[i-1])
 				minh = h[i] - h[i-1];
 		}

 		printf("%lld %lld %lld\n",(ll)(rows-1) * (ll)(col-1),(ll)minv * (ll)minh, (ll)maxv * (ll)maxh);
 	}   

	return 0;
}