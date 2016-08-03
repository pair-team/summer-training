#include <bits/stdc++.h>

using namespace std;
int f[1005];
int v[1005];
int dp[300005];

int main()
{
	int n;
	while(cin >> n && n>=0)
	{
		memset(f,0,sizeof(f));
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			cin >> v[i] >> f[i];
			sum += v[i]*f[i];	
		}
		
		memset(dp,0,sizeof(dp)); 
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=f[i];j++)
			{
				for(int k=sum/2;k>=v[i]*j;k--)
				{
					dp[k] = max(dp[k], dp[k-v[i]]+v[i]);	
				}
			}
		}
		cout << max(dp[sum/2],sum-dp[sum/2]) << " " << min(dp[sum/2],sum-dp[sum/2]) << endl;
	}
	return 0;
 } 
