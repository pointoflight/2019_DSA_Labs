#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int n,k;
 	cin >> n >> k;

 	std::vector<int> v;   
 	std::vector<int> maxs;
 	std::vector<int> mins;

 	for (int i=0;i<n;i++)
 	{
 		int x;
 		cin >> x;
 		v.pb(x);
 	}

 	deque<int> qmax,qmin;

 	qmax.push_back(0);
 	qmin.push_back(0);

 	int i = 1;

 	while (i < k)
 	{
		while (!qmax.empty() && v[qmax.back()] <= v[i])
 			qmax.pop_back();
 		qmax.push_back(i); 		

 		while (!qmin.empty() && v[qmin.back()] >= v[i])
 			qmin.pop_back();
 		qmin.push_back(i);

 		i++;
 	}

 	printf("i=%d\n",i );
 	printf("v[i]=%d\n",v[i] );
 	maxs.push_back(qmax.front());
 	mins.push_back(qmin.front());
 	cout << "max = " << v[qmax.front()] << endl;
 	cout << "min = " << v[qmin.front()] << endl;


 	while (i < n)
 	{
 		while (!qmax.empty() && v[qmax.back()] <= v[i])
 			qmax.pop_back();
 		qmax.push_back(i);

 		while (i - qmax.front() >= k)
 			qmax.pop_front();

 		while (!qmin.empty() && v[qmin.back()] >= v[i])
 			qmin.pop_back();
 		qmin.push_back(i);

 		while (i - qmin.front() >= k)
 			qmin.pop_front();

 		cout << "max = " << v[qmax.front()] << endl;
 		cout << "min = " << v[qmin.front()] << endl;
 		maxs.pb(qmax.front());
 		mins.pb(qmin.front());
 		i++;
 	}

 	// for (int i=0;i<maxs.size();i++)
 	// {
 	// 	printf("%d ",maxs[i] + mins[i]);
 	// }
 	// cout << endl;

	return 0;
}