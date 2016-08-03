#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int dis[maxn][maxn];
int l[maxn],r[maxn];

int main()
{
	int k;
	cin >> k;
	while(k--)
	{
		int m,n;
		cin >> m >> n;
		char c;
		memset(dis,-1,sizeof(dis));
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)	
			{
				cin >> c;
				if(c == 'R')
					dis[i][j] = 0;
				else if(c == 'F' && i == 1)
					dis[i][j] = 1;
				else
					dis[i][j] = dis[i-1][j] + 1;
			}
					
		int ans = 0;
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=1;j--)
			{
				r[j] = j;
				while(r[j] <= n && dis[i][r[j]+1] >= dis[i][j])
					r[j] = r[r[j]+1];
			}
			for(int j=1;j<=n;j++)
			{
				l[j] = j;
				while(l[j] >= 1 && dis[i][l[j]-1] >= dis[i][j])
					l[j] = l[l[j]-1];
			}
			
			for(int j=1;j<=n;j++)
				ans = max(ans, (r[j]-l[j]+1)*dis[i][j]);
		}
		cout << ans*3 << endl;	
	} 
	return 0;
}
