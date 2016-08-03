#include <bits/stdc++.h>

using namespace std;
const int maxn = 35;
struct blocks{
	int a,b,c;
	
	bool operator <  (const blocks &block) const
	{
		if(a == block.a)
		{
			if(b == block.b)
			{
				return c < block.c;
			}
			return b < block.b;
		}
		return a < block.a;
	}
	
}blo[maxn*3];

int dp[maxn*3];

int main()
{
	int n;
	int casen = 1;
	while(cin >> n && n)
	{
		int cnt = 0;
		int a,b,c;
		for(int i=0;i<n;i++)
		{
			cin >> a >> b >> c;
			blo[cnt].a = max(a,b);
			blo[cnt].b = min(a,b);
			blo[cnt++].c = c;
		
			blo[cnt].a = max(a,c);
			blo[cnt].b = min(a,c);
			blo[cnt++].c = b;
		
			blo[cnt].a = max(b,c);
			blo[cnt].b = min(b,c);
			blo[cnt++].c = a;
		}
		
		sort(blo,blo+cnt);
		
		int ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<cnt;i++)
		{
			dp[i] = blo[i].c; 
			for(int j=0;j<i;j++)
			{
				//printf("%d %d %d %d\n",blo[i].a*blo[i].b,blo[j].b*blo[j].a,blo[i].c,blo[j].c);
				if(blo[i].a > blo[j].a && blo[i].b > blo[j].b && dp[j] + blo[i].c > dp[i])
				{
					dp[i] = dp[j] + blo[i].c;
					ans = max(ans,dp[i]);
				}
			}
		}
		printf("Case %d: maximum height = %d\n",casen++,ans);
	}
	  
	return 0;
}
