#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool isoperator(string s)
{
	char c = s[0];
	if (c == '+' || c == '-' || c == '/' || c == '*' || c=='^')
		return true;

	return false;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	stack<string> s;

 	int n;
 	cin >> n;

 	std::vector<string> v;   

 	for (int i=0;i<n;i++)
 	{
 		char c;
 		cin >> c;
 		string s(1,c); 
 		v.pb(s);
 	}

 	for (int i=0;i<=(n/2);i++)
 	{
 		string temp = v[i];
 		v[i] = v[n-i-1];
 		v[n-i-1] = temp;
 	}

 	int i = 0;

 	while (i < n)
 	{
 		if (isoperator(v[i]))
 		{
 			string s1 = s.top();
 			s.pop();
 			string s2 = s.top();
 			s.pop();
 			s1.append(s2);
 			s1.append(v[i]);
 			s.push(s1);
 		}
 		else
 			s.push(v[i]);
 		//printf("%d\n",i);
 		i++;
 	}

 	string ans = s.top();

 	cout << ans << endl;

	return 0;
}