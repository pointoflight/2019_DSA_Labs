#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}
string conv(int a, int b)
{
	int g = gcd(abs(a),abs(b));
	a /= g;
	b /= g;

	string c = "+";

	if (a * b < 0)
		c = "-";

	string s = c + to_string(abs(a)) + '/' + to_string(abs(b));

	return s;

}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    cout.tie(NULL);

 	int n;
 	cin >> n;

 	std::vector<int> a; 
 	std::vector<int> b;

 	for (int i=0;i<n;i++)
 	{
 		int x;
 		cin >> x;
 		a.pb(x);
 	}  

 	for (int i=0;i<n;i++)
 	{
 		int x;
 		cin >> x;
 		b.pb(x);
 	}

 	unordered_map<string,int> umap;

 	for (int i=0;i<n;i++)
 	{
 		if (a[i] == 0 || a[i] != 0 && b[i] == 0)
 			continue;
 		string s = conv(a[i],b[i]);
 		if (umap.find(s) == umap.end())
 			umap[s] = 1;
 		else
 			umap[s]++;
 	}

 	int max = 0;
 	for (auto x : umap)
 	{
 		if (max < x.second)
 			max = x.second;
 	//	cout << x.first << " " << x.second << endl;

 	}

 	int anywayzero = 0;
 	for (int i=0;i<n;i++)
 	{
 		if (a[i] == 0 && b[i] == 0)
 			anywayzero++;
 	}

 	max += anywayzero;
 	int max1 = 0;

 	// check for d = 0;
 	// for (int i=0;i<n;i++)
 	// {
 	// 	if (b[i] == 0)
 	// 		max1++;
 	// }

 	// if (max1 > max)
 	// 	max = max1;

 	cout << max << endl;

	return 0;
}