#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
long double calculatetimederivative(long double mid,long double x,long double y,long double z,long double k)
{
    return (mid/(sqrt(x*x + mid*mid))) - k*(z-mid)/(sqrt((z-mid)*(z-mid) + y*y));
}
long double calculatedistance(long double mid,long double x,long double y,long double z,long double k)
{
    return ((sqrt(x*x + mid*mid))) + (sqrt((z-mid)*(z-mid) + y*y));
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int t;
    cin >> t;
    while (t--)
    {
        long double x,y,z,k;
        cin >> x >> y >> z >> k;

        long double left = 0, right = z, mid=z;

        long double timederivative = 100000;

        while (left < right - 0.001)
        {
            mid = (left + right)/2;
            timederivative = calculatetimederivative(mid,x,y,z,k);

            if (timederivative < 0)
                left = mid;
            else if (timederivative > 0)
                right = mid;
            else
                break;
        }

        long double ans = calculatedistance(mid,x,y,z,k);
        cout << std::setprecision(15) << ans << endl;
    }

    return 0;
}