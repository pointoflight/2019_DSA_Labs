
// find frequency of an element x in a given array. logn

int n,x;
cin >> n >> x;

std::vector<int> v;

for (int i=0;i<n;i++)
{
	int c;
	cin >> c;
	v.pb(c);
}


auto lo = lower_bound(v.begin(),v.end(),x);
auto high = upper_bound(v.begin(),v.end(),x);

cout << high - lo << endl;


-----------------------------------------------


// given an array of n elements where n is odd, find the maximum possible value of median. operation - can increase any element by 1. can do this operation at most once
bool check(int mid, std::vector<int> v)
{	
	// change median to mid
	int ops = 0;
	for (int i=n/2;i<n;i++)
	{
		if (v[i] - mid >= 0)
			break;
		ops += mid - v[i];
	}

	if (ops <= k)
		return true;

	return false;
}
int n,x;

std::vector<int> v;

for (int i=0;i<n;i++)
{
	int x;
	cin >> x;
	v.pb(x);
}

sort(v.begin(),v.end());

// binary search on possible median values. median values can range from 1 to 2*10^9. (from the question constraints)

int left = 1, right = 2000000000, mid;

while (left < right)
{
	mid = (left + right) / 2;

	if (check(mid))
		left = mid;
	else
		right = mid-1;
}
