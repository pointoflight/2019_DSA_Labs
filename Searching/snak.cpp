#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool check(int mid, int lengthreq, std::vector<int> length)
{
	int n = length.size();
	int leftforeat = n - mid;
	int c = 0;

	for (int i = leftforeat;i<n;i++)
	{
		if (length[i] < lengthreq)
			c += lengthreq - length[i];
		else
			break;
		if (c > leftforeat)
			break;
	}
	if (c <= leftforeat)
		return true;
	else
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
 		int n,q;
 		cin >> n >> q;
 		std::vector<int> length;

 		for (int i=0;i<n;i++)
 		{
 			int x;
 			cin >> x;
 			length.pb(x);
 		}

 		sort(length.begin(), length.end());
 		std::vector<int> queries;

 		for (int i=0;i<q;i++)
 		{
 			int x;
 			cin >> x;
 			queries.pb(x);
 		}

 		for (int i=0;i<q;i++)
 		{
 			// queries[i] 
 			int left = 0, right = n, mid;

 			while (left < right)
 			{
 				mid = (left + right + 1) / 2;

 				if (check(mid,queries[i],length))
 					left = mid;
 				else
 					right = mid - 1;
 				// printf("left = %d right = %d mid = %d\n",left,right,mid);
 				// if (check(mid,queries[i],length))
 				// 	printf("yes\n");
 			}
 			cout << left << endl;
 			//printf("%d\n",i);
 		}
 	}   

	return 0;
}