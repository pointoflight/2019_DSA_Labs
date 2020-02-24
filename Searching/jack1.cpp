#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
float calculate(float mid, float x, float y, float z, float k)
{
	return (mid/(sqrt(x*x + mid*mid))) - k*(z-mid)/(sqrt((z-mid)*(z-mid) + y*y));
}
float calculate1(float mid, float x, float y, float z, float k)
{
	return (sqrt(x*x + mid*mid)) + (sqrt((z-mid)*(z-mid) + y*y));
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int t;
    cin >> t;
    while (t--)
    {
    	float x,y,z,k;
    	cin >> x >> y >> z >> k;

    	float left = 0, right = z,mid,timederi=10000000;

    	float delta = 10000000;
    	float min = calculate(mid,x,y,z,k);
    	while (abs(timederi) >= 0.00001)
    	{
    		mid = (left + right)/2;
    		printf("mid = %0.6f\n",mid );

    		float timederi = calculate(mid,x,y,z,k);
    		printf("timederi = %0.6f\n",timederi);

    		delta = min - timederi;
    		printf("delta = %0.6f\n", delta);
    		if (timederi < min)
    			min = timederi;
    		if (timederi < 0)
    		{
    			left = mid;
    		}
    		else if (timederi > 0)
    			right = mid;
    		else
    			break;
    	}

    	printf("%0.6f\n", calculate1(mid,x,y,z,k)); 
    }

	return 0;
}