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
   		std::vector<ll> v;
   		for (int i=0;i<n;i++)
   		{
   			ll x;
   			cin >> x;
   			v.pb(x);
   		}

   		stack<ll> stack;
   		std::vector<ll> ans;
   		for (int i=0;i<n;i++)
   			ans.pb(0);

   		int w = n-1;

   		while(w >= 0)
   		{
   			if (stack.empty())
   			{
   				ans[w] = -1;
   				stack.push(v[w]);
   				w--;
   				continue;
   			}	

   			while (!stack.empty() && v[w] >= stack.top())
   				stack.pop();

   			if (stack.empty())
   			{
   				ans[w] = -1;
   				stack.push(v[w]);
   				w--;
   				continue;
   			}	

   			ans[w] = stack.top();
   			stack.push(v[w]);
   			w--;
   		}

   		for (int i=0;i<n;i++)
   			printf("%lld ",ans[i]);
   		printf("\n");
   	}

    

	return 0;
}