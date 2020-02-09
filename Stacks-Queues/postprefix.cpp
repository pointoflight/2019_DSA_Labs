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

void prints(stack<string> s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

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

 	stack<string> s;

 	int c = 0;
 	for (int i=0;i<n;i++)
 	{
 		if (isoperator(v[i]))
 		{
 			string s1 = s.top();
 			s.pop();
 			string s2 = s.top();
 			s.pop();
 			string news = v[i] + s2 + s1;
 			s.push(news);
 		}	
 		else
 			s.push(v[i]);
 	}

 	string ans = s.top();
 	cout << ans << endl;

	return 0;
}