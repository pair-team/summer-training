#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;
int value[maxn];
int dp[maxn];

int main()
{
	double total;
	int num;
	while(cin >> total >> num && num)
	{
		for(int i=0;i<num;i++)
		{
			int m;
			cin >> m;
			int sum = 0;
			int typecnt[4];
			memset(typecnt,0,sizeof(typecnt));
			bool flag = true;
			for(int j=0;j<m;j++)
			{
				char type,c;
				double v;
				cin >> type >> c >> v;
				if(type > 'C')
				{
					flag = false;
					continue;
				}
				typecnt[type-'A'] += v*100;
				sum += (v*100);
				if(typecnt[type-'A'] > 60000)
					flag = false;
			}
			if(sum <= 100000 && flag)
			{
				value[i] = sum;
			}
			else
			{
				value[i] = 0;
			}
		}
		
		memset(dp,0,sizeof(dp));
		for(int i=0;i<num;i++)
		{
			for(int j=num;j>=1;j--)
			{
				if(dp[j-1] + value[i] <= total*100)
					dp[j] = max(dp[j], dp[j-1]+value[i]);
				//cout << dp[j] << endl;
			}
		}
		
		int ans = 0;
		for(int i=num;i>=1;i--)
		{
			if(dp[ans] < dp[i])
				ans = i;
		}
		printf("%.2lf\n",dp[ans]/100.0);
	}
	return 0;
 } 
