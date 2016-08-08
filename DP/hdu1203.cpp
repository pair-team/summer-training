#include <bits/stdc++.h>

using namespace std;
const int maxn = 10005;
double dp[maxn];
int cost[maxn];
double p[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin >> n >> m && (n || m))
	{
		for(int i=0;i<m;i++)
		{
			cin >> cost[i] >> p[i];
			p[i] = 1 - p[i];
		}
		
		for(int i=0;i<=n;i++)
			dp[i] = 1.0;
		for(int i=0;i<m;i++)
		{
			for(int j=n;j>=cost[i];j--)
			{
				dp[j] = min(dp[j],dp[j-cost[i]]*p[i]);
			}
		}
		printf("%.1lf%%\n",(1-dp[n])*100);
	}	
		
	return 0;
}
