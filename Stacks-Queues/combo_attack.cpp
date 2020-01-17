#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

bool compare(pair<ll,ll>a,pair<ll,ll>b)
{
	if (a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

std::vector<ll> findque(ll time, std::vector<ll> initialque, ll t1, ll t2)
{
	ll n = initialque.size();
	std::vector<ll> res;

	ll timegap;
	
	if (n!=0)
	{
		timegap = time - t1;
		if (timegap >= n)
		{
			ll quotient = timegap / n;
			timegap -= quotient * n;
		}

		for (ll i=timegap;i<n;i++)
		{
			res.pb(initialque[i]);
		}
		for (ll i=0;i<timegap;i++)
			res.pb(initialque[i]);
	}

	return res;
}
pair<vector<ll>, ll> findnexttime(ll curtime, std::vector<ll> curq, std::vector<ll> hitsleft, ll guyleaving){
	  
	 ll reachfront, hishitsleft;
  	ll members = curq.size();
  	//prllf("numhits[guyleaving = %d\n",hitsleft[guyleaving] );
  	for (ll i=0;i<members;i++)
  	{
  		if (curq[i] == guyleaving)
  			{
				reachfront = i;
				hishitsleft = hitsleft[curq[i]];
				//prllf("i = %d hitsleft[i] = %d\n",i,hitsleft[i]);
			}
  	}

  	ll totaltime = 1 + (hishitsleft-1)*(members) + reachfront;
  	// prllf("hishitsleft = %d \n",hishitsleft );
  	// prllf("members = %d \n",members );
  	// prllf("reachfront = %d \n",reachfront);
  	// prllf("totaltime 28 : %d \n",totaltime );
  	std::vector<ll> newhitsleft = hitsleft;
  	ll gotindex;
  	ll gotem = 0;
  	// prllf("{ { { { {\n" );
  	// prllf("guyleaving in function = %d\n",guyleaving);

  	for (ll i=0;i<curq.size();i++){

  		if (curq[i] == guyleaving)
  			{
  				gotem = 1;
  				gotindex = i;
  			}
  		// else if (gotem == 0)
  		// {
  		// 	newhitsleft[i] -= hitsleft[guyleaving];
  		// }
  		// else
  		// {
  		// 	newhitsleft[i] -= hitsleft[guyleaving];
  		// 	newhitsleft[i]++;
  		// }
  	}
  //	prllf("hishitsleft = %d\n",hishitsleft );
  	for (ll i=0;i<curq.size();i++)
  	{
  		if (i<gotindex)
  			newhitsleft[curq[i]] -= hishitsleft;
  		else
  			newhitsleft[curq[i]] -= hishitsleft-1;
  	}
  	newhitsleft[guyleaving] = 0;
  	// prllf("%d %d \n",newhitsleft[2],newhitsleft[3] );

  	// prllf("gotem = %d\n",gotem );
  	// prllf("gotindex = %d\n",gotindex );
  	// prllf("} } } }\n");
  	return (mp(newhitsleft,totaltime));
}

void printque(queue<ll> q){

	while (!q.empty())
	{
		printf("%lld ",q.front() );
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    ll n,k,q;
    cin >> n >> k >> q;

    std::vector<ll> numhits;

    numhits.pb(0);
    
    for (ll i=0;i<n;i++){
    	ll x;
    	cin >> x;
    	numhits.pb(x);
    }

    numhits[1] /= k;

    std::vector<ll> queries;

    for (ll i=0;i<q;i++)
    {
    	ll x;
    	cin >> x;
    	queries.pb(x);
    }

    std::vector<pair<ll,ll> > gofirst;

    for (ll i=1;i<=n;i++){

    	gofirst.pb(mp(numhits[i],i));
    }

    sort(gofirst.begin(),gofirst.end(),compare);

    std::vector<ll> timestheygo;

    timestheygo.pb(0);

    ll curtime = 0;

    queue<ll> curque;

    std::vector<ll> curquevec;

    for (ll i=1;i<=n;i++)
    	curquevec.pb(i);

    for (ll i=1;i<=n;i++)
    	curque.push(i);

    //////// start testing

//    pair<std::vector<ll>, ll> pairob = findnexttime(curtime, curquevec, numhits, gofirst[0].second);
    
   //  pair<std::vector<ll>, ll> pairob = findnexttime(curtime, curquevec, numhits, gofirst[0].second);
  	
  	// prllf("numhits : ");

   //  curtime += pairob.second;

   //  numhits = pairob.first;

   //  prllf("numhits at 128 : ");
   //  for (ll i=0;i<numhits.size();i++)
   //  	prllf("%d ",numhits[i]);
   //  prllf("\n");
   //  std::vector<ll> addtoque;
   //  	while (curque.front() != gofirst[0].second)
   //  	{
   //  		addtoque.pb(curque.front());
   //  		curque.pop();
   //  	}
   //  	prllf("curque at 144 : ");
   //  	prllque(curque);
   //  	prllf("\n");
   //  	curque.pop();
   //  	prllf("curque at 148 : ");
   //  	prllque(curque);
   //  	prllf("\n");
   //  	for (ll i=0;i<addtoque.size();i++)
   //  		curque.push(addtoque[i]);

   //  	queue<ll> temp = curque;
   //  	std::vector<ll> newcurquevec;

   //  	while (!temp.empty())
   //  	{
   //  		newcurquevec.pb(temp.front());
   //  		temp.pop();
   //  	}

   //  	curquevec.clear();
   //  	curquevec = newcurquevec;

   //  	  prllf("curtime = %d\n",curtime );
    
   //  prllf("curque : "); 
   //  prllque(curque);
   //  prllf("\n");
   //  prllf("numhits : ");
   //  for (ll i=1;i<=n;i++)
   //  	prllf("%d ",numhits[i]);
   //  prllf("\n");
   //  prllf("guyleaving = %d\n",gofirst[1].second);

   //  prllf("1 %d  \n",gofirst[0].second);
   //  prllf("2 %d  \n",gofirst[1].second );
    	///////// end testing

    map<ll,std::vector<ll> > map;
    std::vector<ll> temp1;
    for (ll i=1;i<=n;i++)
    {
    	temp1.pb(i);
    }
    map.insert(mp(0,temp1));

    for (ll i=0;i<n;i++){

    	ll guyleaving = gofirst[i].second;

    	pair<std::vector<ll>, ll> pairob = findnexttime(curtime, curquevec, numhits, guyleaving);

    	numhits = pairob.first;
    	std::vector<ll> addtoque;
    	while (curque.front() != guyleaving)
    	{
    		addtoque.pb(curque.front());
    		curque.pop();
    	}
    	curque.pop();
    	for (ll i=0;i<addtoque.size();i++)
    		curque.push(addtoque[i]);

    	queue<ll> temp = curque;
    	std::vector<ll> newcurquevec;

    	while (!temp.empty())
    	{
    		newcurquevec.pb(temp.front());
    		temp.pop();
    	}
    	curtime += pairob.second;
//    	prllf("%d \n",curtime );
    	curquevec = newcurquevec;
    	timestheygo.pb(curtime);
    	map.insert(mp(curtime,curquevec));

    // 	prllf("curque : "); 
    // prllque(curque);
    // prllf("\n");
    // prllf("curtime = %d\n",curtime);
    // prllf("numhits : ");
    // for (ll i=1;i<=n;i++)
    // 	prllf("%d ",numhits[i]);
    // prllf("\n");
    // prllf("guyleaving = %d\n",gofirst[i].second);
    // prllf("---------------------------\n");
    }

    // for (ll i=0;i<timestheygo.size();i++)
    // 	prllf("%d ",timestheygo[i]);
    // prllf("\n");

    for (ll i=0;i<q;i++)
    {
    	ll time = queries[i];
    	ll t1=-1,t2=-1;

    	for (ll i=0;i<timestheygo.size()-1;i++)
    	{
    		if (time >= timestheygo[i] && time < timestheygo[i+1])
    		{
    			t1 = timestheygo[i];
    			t2 = timestheygo[i+1];
    		}
    	}

    	if (t1==-1)
    		printf("-1\n" );
    	else
    	{
    		std::vector<ll> inique = map.at(t1);
    		std::vector<ll> res = findque(time,inique,t1,t2);
    		if (res.size() == 0)
    			printf("-1\n");
    		else
    		{
    			for (ll i=0;i<res.size();i++)
    			{
    				printf("%lld ",res[i]);
    			}
    			printf("\n");
    		}

    	}
    }



 	   

	return 0;
}