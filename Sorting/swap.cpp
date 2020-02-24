// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends
/* You are required to complete this method */
int minSwaps(int A[], int N){
    /*Your code here */
    int n = N;

    int vis[n];
    for (int i=0;i<n;i++)
    	vis[i] = 0;

    std::vector<int> v;

    for (int i=0;i<n;i++)
    {
    	v.push_back(A[i]);
    }

    sort(v.begin(),v.end());

    int place[n];

    for (int i=0;i<n;i++)
    {
    	for (int j=0;j<n;j++)
    	{
    		if (A[i] == v[j])
    		{
    			place[i] = j;
    			break;
    		}
    	}
    }
    // printf("place\n");
    // for (int i=0;i<n;i++)
    // 	printf("%d ",place[i]);
    int ans = 0;

    for (int i=0;i<n;i++)
    {
    	int count = 1;
    	if (!vis[i])
    	{
    		//cout << "A[i] " << A[i] << endl;
    		int j = place[i];
    		while (j != i)
    		{	
    			vis[j] = 1;
    			//cout << "A[j]=" << A[j] << endl;
    			j = place[j];
    			count++;
    			//cout << "count " << count << endl;
    		}
    	}
    	ans += count-1;
    }

    return ans;
}
