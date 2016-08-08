#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
int exper[maxn];
int lasting[maxn];
int dp[maxn][maxn];

int main()
{
	int n,m,k,s;
	while(cin >> n >> m >> k >> s)
	{
		for(int i=0;i<k;i++)
			cin >> exper[i] >> lasting[i];
		
		memset(dp,0,sizeof(dp));
		for(int i=0;i<k;i++)
		{
			for(int j=lasting[i];j<=m;j++)
			{
				for(int t=1;t<=s;t++)
				{
					dp[j][t] = max(dp[j][t],dp[j-lasting[i]][t-1]+exper[i]);
				}
			}
		}
		
		int ans = -1;
		bool flag = false;
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=s;j++)
			{
				if(dp[i][j] >= n)
				{
					ans = i;
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag)
		cout << m-ans << endl;
		else
		cout << ans << endl;
	}
	return 0;
}
