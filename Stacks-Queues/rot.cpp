#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

 	int t;
 	cin >> t;
 	while (t--)
 	{
 		int r,c;
 		cin >> r >> c;
 		int a[r][c];
 		queue<pair<int,int> >q;

 		for (int i=0;i<r;i++)
 		{
 			for (int j=0;j<c;j++)
 			{
 				int x;
 				cin >> x;
 				a[i][j] = x;
 				if (x == 2)
 					q.push(mp(i,j));
 			}
 		}
 		q.push(mp(-1,-1));

 		// while (!q.empty())
 		// 	{
 		// 		printf("%d %d\n",q.front().first, q.front().second);
 		// 		q.pop();
 		// 	}

 		int ans = 0;
 		while (!q.empty())
 		{
			int x = q.front().first, y = q.front().second;
			if (x == -1)
			{
				ans++;
				q.pop();
				if (!q.empty())
				{
					q.push(mp(-1,-1));
				}
				continue;
			}
			// printf("x,y = %d,%d\n",x,y);
			// printf("a[x+1][y] = %d\n",a[x+1][y] );
			// printf("%d %d\n",r,c);
			// printf("a[x][y]\n");
			if (x + 1 < r && y < c && a[x+1][y] == 1)
			{
				q.push(mp(x+1,y));
				a[x+1][y] = 2;
			}
			if (x < r && y + 1 < c && a[x][y+1] == 1)
			{
				q.push(mp(x,y+1));
				a[x][y+1] = 2;
			}
			if (x - 1 >= 0 && y < c && a[x-1][y] == 1)
			{
				q.push(mp(x-1,y));
				a[x-1][y] = 2;
			}
			if (x < r && y - 1 >= 0 && a[x][y-1] == 1)
			{
				q.push(mp(x,y-1));
				a[x][y-1] = 2;
			}
			q.pop();
		
			// for (int p=0;p<r;p++)
			// {
			// 	for (int q1=0;q1<c;q1++)
			// 	{
			// 		printf("%d ",a[p][q1]);
			// 	}
			// 	printf("\n");
			// }
			//printf("queue;\n");
			// queue<pair<int,int> >  q1 = q;
			// while (!q1.empty())
 		// 	{
 		// 		printf("%d %d\n",q1.front().first, q1.front().second);
 		// 		q1.pop();
 		// 	}
 		}

 		bool flag = true;

 		for (int i=0;i<r;i++)
 		{
 			for (int j=0;j<c;j++)
 			{
 				if (a[i][j] == 1)
 				{
 					flag = false;
 					break;
 				}
 			}
 		}
 		if (flag == false)
 			cout << -1 << endl;
 		else
 		cout << ans-1 << endl;


 		// for (int p=0;p<r;p++)
			// {
			// 	for (int q1=0;q1<c;q1++)
			// 	{
			// 		printf("%d ",a[p][q1]);
			// 	}
			// 	printf("\n");
			// }
 	}   

	return 0;
}