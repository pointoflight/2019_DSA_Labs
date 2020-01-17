#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

     ll n;
     cin >> n;

     std::vector<ll> v;   

    queue<ll> q;
     stack<ll> s;
     
     for (ll i=0;i<n;i++){
         ll x;
         cin >> x;
         v.pb(x);
     }

     std::vector<ll> premin;
     for (ll i=0;i<n;i++)
         premin.pb(-1);

     //cout << v.size() << endl;
     //cout << n << endl;
     ll min = v[v.size()-1];

     for (ll i = v.size()-1;i>=0;i--)
     {
         if (min > v[i])
         {
             min = v[i];
             premin[i] = min;
         }
         else
             premin[i] = min;
     }

     // for (ll i=0;i<n;i++)
     //     cout << premin[i] << endl;

     for (ll i=0;i<n;i++){

         if (v[i] == premin[i]){

             if (s.empty()){
                 q.push(v[i]);
             }
             else
             {
                 ll topmost = s.top();
                 while (topmost <= v[i] && !s.empty()){
                     q.push(topmost);
                     s.pop();
                     if (!s.empty())
                         topmost = s.top();
                 }
                q.push(v[i]);
             }
         }
         else
         {
             s.push(v[i]);
         }
     }

     while (!q.empty())
     {
         cout << q.front() << " ";
         q.pop();
     }

     while (!s.empty())
     {
         cout << s.top() << " ";
         s.pop();
     }

    return 0;
}