#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool check(int mid, string s, int k)
{	
	int n = s.size();

	char cur = s[0];
	int count = 1;
	int totalchanges = 0;
	for (int i=1;i<n;i++)
	{
		if (s[i] == cur)
		{
			if (count == mid)
			{
				totalchanges++;
				count = 1;
				if (cur == '1')
					cur = '0';
				else
					cur = '1';
			}
			else
			{
				count++;	
			}
		}	
		else
		{
			count = 1;
			if (cur == '1')
				cur = '0';
			else
				cur = '1';
		}
	}
	if (totalchanges <= k)
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
 		int n,k;
 		cin >> n >> k;

 		string s;
 		cin >> s;

 		int left = 1, right = n, mid;

 		while (left < right)
 		{
 			mid = (left + right) / 2;
 			if (check(mid,s,k))
 				right = mid;
 			else
 				left = mid + 1;
 		}
 		// check if l=1 is possible.

 		// char cur = '1';
 		// bool flag1 = true;
 		// for (int i=0;i<n;i++)
 		// {
 		// 	if (s[i] != cur)
 		// 		flag1 = false;
 		// 	if (cur == '1')
 		// 		cur = '0';
 		// 	else
 		// 		cur = '1';
 		// }

 		// cur = '0';
 		// bool flag2 = true;
 		// for (int i=0;i<n;i++)
 		// {
 		// 	if (s[i] != cur)
 		// 		flag2 = false;
 		// 	if (cur == '1')
 		// 		cur = '0';
 		// 	else
 		// 		cur = '1';
 		// }

 		// if (flag1 || flag2)
 		// 	right = 1;

 		cout << right << endl; 
 	}   

	return 0;
}