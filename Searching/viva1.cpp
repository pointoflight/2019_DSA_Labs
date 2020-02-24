#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool check(ll mid, std::vector<int> times, int n)
{
	int groupscompleted = 0;
	
	for (int i=0;i<times.size();i++)
		groupscompleted += mid / times[i];
	
	if (groupscompleted >= n - times.size())
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
 		int m,n;
 		cin >> m >> n;

 		std::vector<int> times;

 		for (int i=0;i<m;i++)
 		{
 			int x;
 			cin >> x;
 			times.pb(x);
 		}

 		ll left = 0, right = 10e16, mid;

 		while (left < right)
 		{
 			mid = (left + right) / 2;

 			if (check(mid,times,n))
 				right = mid;
 			else
 				left = mid + 1;
 		}

 		ll ourslot = right;

 		printf("our group time = %lld \n",ourslot);

 	}   

	return 0;
}