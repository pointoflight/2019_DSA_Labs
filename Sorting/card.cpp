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

 		int nots = -1;

 		for (int i=0;i<=n-2;i++)
 		{	
 			// printf("%d\n",v[i]);
 			if (v[i+1] < v[i])
 				{
 					nots = i+1;
 					break;
 				}
 		}

 		if (nots == -1)
 			cout << "YES" << endl;
 		else
 		{
 			std::vector<int> mod;
 			for (int i=nots;i<n;i++)
 				mod.pb(v[i]);
 			for (int i=0;i<nots;i++)
 				mod.pb(v[i]);
 			
 			bool sorted = true;

 			for (int i=0;i<n-1;i++)
 			{
 				if (mod[i+1] < mod[i])
 				{
 					sorted = false;
 					break;
 				}
 			}
 			// printf("nots = %d\n",nots);

 			// for (int i=0;i<n;i++)
 			// 	cout << mod[i] << " ";
 			//cout << endl;
 			if (sorted)
 				cout << "YES" << endl;
 			else
 				cout << "NO" << endl;
 		}
 	}   

	return 0;
}