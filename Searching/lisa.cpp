#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
bool check(ll mid, ll m, std::vector<ll> amountneededinoneserving, std::vector<ll> amountavailable, std::vector<ll> sizeofsmall,std::vector<ll> sizeoflarge, std::vector<ll> pricesmall, std::vector<ll> pricelarge)
{	
	ll n = amountneededinoneserving.size();
	for (ll i=0;i<n;i++)
	{
		// check if this item is available for mid servings;
		ll totalamountneeded = amountneededinoneserving[i] * mid;
		totalamountneeded -= amountavailable[i];
		ll numberoflarge = totalamountneeded / sizeoflarge[i];
		ll numberofsmall = totalamountneeded / sizeofsmall[i];
		ll costoflarge = numberoflarge * pricelarge[i];
		ll costofsmall = numberofsmall * pricesmall[i];
		//printf("totalamountneeded = %lld numberofsmall = %lld numberoflarge = %lld costofsmall = %lld costoflarge = %lld\n",totalamountneeded,numberofsmall,numberoflarge,costofsmall,costoflarge);
		if (costofsmall < costoflarge)
		{
			totalamountneeded -= numberofsmall * sizeofsmall[i];
			m -= costofsmall;
		}
		else
		{
			totalamountneeded -= numberoflarge * sizeoflarge[i];
			m -= costofsmall;
		}

		if (totalamountneeded > 0)
		{
			if (pricesmall[i] < pricelarge[i])
			{
				m -= pricesmall[i];
				totalamountneeded -= sizeofsmall[i];
			}
			else
			{
				m -= pricelarge[i];
				totalamountneeded -= sizeoflarge[i];
			}
			//printf("m = %lld\n",m);
		}
	}
	if (m < 0)
		return false;
	else
		return true;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	ll n,m;
 	cin >> n >> m;

 	std::vector<ll> amountneededinoneserving;
 	std::vector<ll> amountavailable;
	
	std::vector<ll> sizeofsmall;
	std::vector<ll> sizeoflarge;
	std::vector<ll> pricesmall;
	std::vector<ll> pricelarge;

	for (ll i=0;i<n;i++)
	{
		ll a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		amountneededinoneserving.pb(a);
		amountavailable.pb(b);
		sizeofsmall.pb(c);
		pricesmall.pb(d);
		sizeoflarge.pb(e);
		pricelarge.pb(f);
	}
	

	ll left = 0, right = 1000000000, mid;

	while (left < right)
	{
		mid = (left + right + 1)/ 2;
		if(check(mid,m,amountneededinoneserving,amountavailable,sizeofsmall,sizeoflarge,pricesmall,pricelarge))
			left = mid;
		else
			right = mid-1;
		//printf("left = %lld right = %lld mid = %lld\n",left,right,mid );
	}

	cout << left+1 << endl;

	return 0;
}