#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool check(ll mid, std::vector<int> times, int n)
{
	ll totalgroupsdone = 0;
	for (int i=0;i<times.size();i++)
		totalgroupsdone += mid / times[i];
	
	if (totalgroupsdone >= n-times.size())
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

    	ll left = 0, right = 10e15, mid;

    	while (left < right)
    	{
    		mid = (left + right) / 2;
    		if (check(mid,times,n))
    			right = mid;
    		else
    			left = mid + 1;
    	}

    	ll ourslot = right;
    	
    	// our slot at time = right;
    	//printf("our slot = %lld\n",right);
    	int peopleinourslot = 0;
    	for (int i=n-1;i>=n-m+1;i--)
    	{
            left = 0, right = 10e15;
    		while (left < right)
	    	{
	    		mid = (left + right) / 2;
	    		if (check(mid,times,n))
	    			right = mid;
	    		else
	    			left = mid + 1;
	    	}
	    	if (right == ourslot)
	    	{
	    		peopleinourslot++;
	    	}
	    	else
	    		break;
    	}
    	printf("peopleinourslot = %d\n",peopleinourslot );
    	std::vector<int> freeteachers;

    	for (int i=0;i<m;i++)
    	{
    		if (ourslot % times[i] == 0)
    			freeteachers.pb(i);
    	}

    	sort(freeteachers.begin(),freeteachers.end());
    	printf("free teachers : ");
    	for (int i=0;i<freeteachers.size();i++)
    		printf("%d ",freeteachers[i]);
    	cout << endl;
    	cout << freeteachers[peopleinourslot] + 1 << endl;
    }

	return 0;
}