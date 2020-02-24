#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string normalize(int numerator, int denominator) {
    bool sign = (ll(numerator) * ll(denominator)) < 0;
    int gcd0 = __gcd(abs(numerator), abs(denominator));
    numerator = abs(numerator/gcd0);
    denominator = abs(denominator/gcd0);

    string frac = (sign ? "-" : "+") 
                    + to_string(numerator)
                    + "/"
                    + to_string(denominator);

    return frac;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int a[n], b[n];

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    for(int i=0; i<n; i++) {
        cin>>b[i];
    }

    int ans=0, cnt_zero=0;

    unordered_map<string, int> hash;

    string frac;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            if(b[i] == 0) {
                cnt_zero++;
            }
        }
        else {
            frac = normalize(-b[i], a[i]);
            //cout<<-b[i]<<" "<<a[i]<<" "<<frac<<"\n";
            hash[frac]++;

            if(hash[frac] > ans)
                ans = hash[frac];
        }
    }

    cout<<ans + cnt_zero<<"\n";

}