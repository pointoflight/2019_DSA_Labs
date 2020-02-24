#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
void merge(std::vector<int> &v, int lo, int hi)
{
	int mid = (lo + hi)/2;
	// printf("merge\n");
	// printf("lo = %d hi = %d mid = %d\n",lo,hi,mid);
	std::vector<int> v1,v2;
	
	for (int i=lo;i<=mid;i++)
		v1.pb(v[i]);

	for (int i=mid+1;i<=hi;i++)
		v2.pb(v[i]);

	// cout << "v1 ";
	// 	for (int i=0;i<v1.size();i++)
	// 	cout << v1[i] << " ";
	// cout << endl;

	// cout << "v2 ";
	// 	for (int i=0;i<v2.size();i++)
	// 	cout << v2[i] << " ";
	// cout << endl;
	

	int p1 = 0, p2 = 0;
	//printf("is this p1=%d p2=%d\n %d %d",p1,p2,v1[0],v2[0]);
	int i=lo;
	//printf("%d %d\n",v1[p1],v2[p2]);
	while (p1 < v1.size() && p2 < v2.size())
	{
		if (v1[p1] < v2[p2])
		{
			v[i] = v1[p1];
			p1++;
		}
		else
		{
			v[i] = v2[p2];
			p2++;
		}
		i++;
		// printf("p1=%d p2=%d\n",p1,p2);
	}

	while (p1 < v1.size())
	{
		v[i] = v1[p1];
		i++;
		p1++;
	}
	while (p2 < v2.size())
	{
		v[i] = v2[p2];
		i++;
		p2++;
	}
	// printf("after merge\n");
	// for (int i=lo;i<hi;i++)
	// 	cout << v[i] << " ";
	// cout << endl;

}
void mergesort(std::vector<int> &v,int lo, int hi)
{
	if (lo == hi)
		return;

	int mid = (lo + hi)/2;
	// printf("in mergesort\n");
	// printf("lo = %d hi = %d mid = %d\n",lo,hi,mid);
	mergesort(v,lo,mid);
	mergesort(v,mid+1,hi);

	merge(v,lo,hi);
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n;
    cin >> n;

    std::vector<int> v(n);

    for (int i=0;i<n;i++)
	    cin >> v[i];
	// 	for (int i=0;i<n;i++)
	// 	cout << v[i] << " ";
	// cout << endl;

	mergesort(v,0,n-1);

	for (int i=0;i<n;i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}












