// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#include <unordered_map> 

int maxPoints(int X[],int Y[],int );              
int main() {
     
     int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
        int x[n];
        int y[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }


        for(int i=0;i<n;i++)
        {
            cin>>y[i];
        }

     
    cout << maxPoints(x,y,n) << endl;
     }
      
    return 0;
}// } Driver Code Ends
/*You are required to complete this method */

int gcd(int a, int b)
{
	while (a != b)
	{
		if (b > a)
			b -= a;
		else if (a > b)
			a-=b;
	}
	return a;
}

string conv(int a, int b)
{
	int g = gcd(abs(a), abs(b));
	a /= g;
	b /= g;

	string c = "+";

	if (a * b < 0)
		c = "-";

	string s = c + to_string(abs(b)) + '/' + to_string(abs(a));

	return s;
}

int maxPoints(int X[], int Y[],int N) {
  
    int max = 2, n = N;

    for (int i=0;i<n;i++)
    {
    	unordered_map <string, int> umap;
    	int overlapping = 0;
    	for (int j=i+1;j<n;j++)
    	{	
    		if (Y[j] == Y[i] || X[j] == X[i])
    			continue;
    		string s = conv(Y[j]-Y[i], X[j]-X[i]);
    		if (umap.find(s) == umap.end())
    			umap[s] = 2;
    		else
    			umap[s]++;
    	}	

    	for (int j=i+1;j<n;j++)
    	{
    		if (Y[j] == Y[i] && X[j] == X[i])
    			overlapping++;
    	}
    	for (auto x : umap)
    	{
    		if (max < x.second + overlapping)
    			max = x.second + overlapping;
    		//cout << x.first << " " << x.second << endl;
    	}

    	int vertical = overlapping + 1;
    	int horizontal = overlapping + 1;

 		for (int j=i+1;j<n;j++)
 		{
 			if (Y[i] == Y[j] && X[i] != X[j])
 				horizontal++;
 			if (X[i] == X[j] && Y[i] != Y[j])
 				vertical++;
 		}

 		if (vertical > max)
 			max = vertical;
 		if (horizontal > max)
 			max = horizontal;
    }
    if (N < 2)
    	return N;

    return max;

}
