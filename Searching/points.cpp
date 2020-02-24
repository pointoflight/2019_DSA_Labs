// { Driver Code Starts
#include <boost/functional/hash.hpp> 
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a < b)
            b-=a;
        else
            a-=b;
    }
    return a;
} 

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
int maxPoints(int X[], int Y[],int N) {
     //Your code here
     int max = 0;
     int n= N;
     
     for (int i=0;i<n;i++)
     {
         
         unordered_map<pair<int, int>, int,boost:: 
              hash<pair<int, int> > > umap; 

         for (int j=0;j<n;j++)
         {
             if (i==j)
             continue;
            int num = Y[j] - Y[i];
            int denum = X[j] - X[i];
            int gcd0 = gcd(num,denum);

            num /= gcd0;
            denum /= gcd0;
            if (umap.find(make_pair(num,denum)) == umap.end())
                umap.insert(make_pair(make_pair(num,denum), 2));
            else
                umap[make_pair(num,denum)]++;
            if (umap[make_pair(num,denum)] > max)
                max = umap[make_pair(num,denum)];
         }
     }
     
     return max;
     
}