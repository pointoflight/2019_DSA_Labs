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

    	std::vector<int> petrol;
    	std::vector<int> distance;

    	for (int i=0;i<n;i++)
    	{
    		int x,y;
    		cin >> x >> y;
    		petrol.pb(x);
    		distance.pb(y);
    	}

    	deque<int> dq;

    	dq.push_back(0);

    	int gasavailable = petrol[0];

    	for (int i=1;i<n;i++)
    	{
    		if (i == n-1)
    		{
    			// check if you can reach to dq.front()
    			bool canreachfront = true;
    		//	printf("gas avail before 42 = %d\n",gasavailable );
    	//		printf("distance 42 = %d\n", distance[i]);

    			if (gasavailable >= distance[i-1])
    			{
    				dq.push_back(i);
    				gasavailable -= distance[i-1];
    				gasavailable += petrol[i];

    				// check if can reach from n-1 to dq.front()
    				if (gasavailable >= distance[n-1])
    				{
    					gasavailable -= distance[n-1];
    					gasavailable += petrol[0];
    				}
    				else
    					canreachfront = false;
    				
    				for (int j=1;j<=dq.front();j++)
    				{
    					if (gasavailable >= distance[j-1])
    					{
    						gasavailable -= distance[j-1];
    						gasavailable += petrol[j];
    					}
    					else
    					{
    						canreachfront = false;
    						break;
    					}
    				}
    				if (canreachfront)
    				{
    					cout << dq.front() << endl;
    					//printf("i=%d\n",i );
    					//printf("65\n");
    					return 0;
    				}
    				else
    				{
    					cout << -1 << endl;
    					return 0;
    				}
    			}
    			else
    			{
    				// start at n-1 and check if tour possible
    				// if not then return -1
    				bool canstartatlast = true;
    				int petrolavail = petrol[n-1];
    				petrolavail -= distance[n-1];
    				if (petrolavail < 0)
    					canstartatlast = false;

    				petrolavail += petrol[0];

    				for (int j=1;j<=n-1;j++)
    				{
    					if (petrolavail >= distance[j-1])
    					{
    						petrolavail -= distance[j-1];
    						petrolavail += petrol[j];
    					}
    					else
    					{
    						canstartatlast = false;
    						break;
    					}
    				}
    				if (canstartatlast)
    				{
    					cout << n-1 << endl;
    					return 0;
    				}
    				else
    				{
    					cout << -1 << endl;
    					return 0;
    				}
    			}
    		}
    		//printf("gas avail = %d\n",gasavailable);
    		if (gasavailable >= distance[i-1])
    		{
    			dq.push_back(i);
    			gasavailable -= distance[i-1];
    			gasavailable += petrol[i];
    		}	
    		else
    		{
    			deque<int> dq1;
    			dq = dq1;
    			dq.push_back(i);
    			gasavailable = petrol[i];
    		}
    	}
    }

	return 0;
}