#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
float calculate(float mid, float x, float y, float z, float k)
{	
	float a = sqrt(x*x + mid * mid) + k * sqrt((z-mid)*(z-mid) + y * y);
	return a;
}
float calculate1(float mid, float x, float y, float z, float k)
{
	float a = sqrt(x*x + mid * mid) + sqrt((z-mid)*(z-mid) + y * y);
	return a;	
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

	 	float ans = calculate(z,x,y,z,k);
	 //	printf("initial ans = %0.6f\n",ans );
	 	float left = 0, right = z;

	 	float delta = 10000.00;
	 	float mid;
	 	int c =0;
	 	while (c < 1000000)
	 	{	
	 		c++;
	 		mid = (left + right)/2;
	 		float timefromleft = calculate(left,x,y,z,k);
	 		float timefromright = calculate(right,x,y,z,k);

	 		// printf("mid = %0.6f\n",mid );
	 		float time = calculate(mid,x,y,z,k);
	 		// printf("time = %0.6f\n",time);
	 		delta = ans - time;
	 		// printf("delta = %0.6f\n",delta);
	 		if (time > ans)
	 		{
	 			// move to the right
	 			if (timefromright > timefromleft)
	 			{
	 				right = mid;
	 			}
	 			else 
	 			{
	 				left = mid;
	 			}
	 		}
	 		else if (time < ans)
	 		{
	 			// move to the left
	 			if (timefromright > timefromleft)
	 			{
	 				right = mid;
	 			}
	 			else 
	 			{
	 				left = mid;
	 			}
	 			
	 			ans = time;
	 		}
	 		// printf("dist = %0.6f\n",calculate1(mid,x,y,z,k) );
	 	}   
	 	// printf("delta = %0.6f\n",delta);
	 	printf("%0.6f\n",calculate1(mid,x,y,z,k));
	}
	return 0;
}