#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
struct rob{
	int money;
	double p;
}r[maxn*maxn];
 
double dp[maxn*maxn];
int sum[maxn];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		double p;
		int n;
		cin >> p >> n;
		p = 1 - p;
		sum[0] = 0;
		for(int i=1;i<=n;i++)
		{
			cin >> r[i].money >> r[i].p;
			r[i].p = 1 - r[i].p;
			sum[i] = sum[i-1] + r[i].money;
		}
		
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=sum[n];j>=r[i].money;j--)
			{
				dp[j] = max(dp[j],dp[j-r[i].money]*r[i].p);
				//cout << j << " " << dp[j] << endl;
			}
		}
		
		int ans = 0;
		for(int j=sum[n];j>=0;j--)
		{
			if(dp[j] > p)
			{
				ans = j;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
 } 
