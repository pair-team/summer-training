#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
int v[25][1005];
int dp[25][1005];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> v[i][j];
			}
		}
		
		for(int i=0;i<=n;i++)
			dp[i][0] = -INF;
		
		for(int j=0;j<=m;j++)
			dp[0][j] = -INF;
			
		dp[0][1] = dp[1][0] = 0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + v[i][j];
				
				int k = 2;
				while(j/k > 0)
				{
					if(j%k == 0)
						dp[i][j] = max(dp[i][j],dp[i][j/k]+v[i][j]);
					k++;
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
 } 
