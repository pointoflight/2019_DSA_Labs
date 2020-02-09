//Merge Overlapping Intervals
 
#include<bits/stdc++.h>
using namespace std;
 
 
void mergeIntervals(vector<pair<int, int>> intervals){
    stack<pair<int, int>> s;
    
    sort(intervals.begin(), intervals.end());
 
    s.push(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
        if(s.top().second < intervals[i].first){
            s.push(intervals[i]);
        }
        else{
            if(s.top().second < intervals[i].second){
                pair<int, int> temp = s.top();
                temp.second = intervals[i].second;
                s.pop();
                s.push(temp);
            }
        }
    }   
    vector<pair<int,int> > ans;
    while(!s.empty()){
        ans.push_back(make_pair(s.top().first, s.top().second));
        s.pop();
    }
    
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
    cout << ans[i].first << " " << ans[i].second << " ";
    cout << endl;
 
}
 
int main()
{

    int t;
    cin >> t;
    while (t--){
	    int n;
	    cin>>n;
	 
	    vector<pair<int, int>> intervals;
	 
	    for(int i=0; i<n; i++){
	        int x, y;
	        cin>>x>>y;
	        intervals.push_back(make_pair(x, y));
	    }
	 
	    mergeIntervals(intervals);
	        
    }
 
}