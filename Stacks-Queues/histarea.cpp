#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n;
    cin >> n;

    std::vector<int> v;

    for (int i=0;i<n;i++)
    {
    	int x;
    	cin >> x;
    	v.pb(x);
    }

    stack<int> s;

    int i=0;
    int max_area = 0;

    while (i < n)
    {
    	if (s.empty() || v[s.top()] <= v[i])
    	{
    		s.push(i);
    		i++;
    	}
    	else
    	{
    		int top = s.top();
    		s.pop();
    		int area = v[top] * (s.empty() ? i : i - s.top() - 1);

    		if (area > max_area)
    			max_area = area;
    	}
    }

    while (!s.empty())
    {
    	int top = s.top();
    	s.pop();

    	int area = v[top] * (s.empty() ? i : i - s.top() - 1);

    	if (area > max_area)
    		max_area = area;
    }

    cout << max_area << endl;

	return 0;
}