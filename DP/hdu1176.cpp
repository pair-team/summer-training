#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 5;
int dp[maxn][15];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n && n)
	{
		memset(dp,0,sizeof(dp));
		int maxT = 0;
		for(int i=0;i<n;i++)
		{
			int t,x;
			cin >> x >> t;
			dp[t][x] ++;
			maxT = max(maxT, t);
		}
		
		for(int i=maxT;i>=0;i--)
		{
			dp[i][0] += max(dp[i+1][0],dp[i+1][1]);
			for(int j=1;j<10;j++)
			{
				dp[i][j]+=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
			}
			dp[i][10] += max(dp[i+1][10],dp[i+1][9]);
		}
	
		
		cout << dp[0][5] << endl;
	}
	
	return 0;
}
