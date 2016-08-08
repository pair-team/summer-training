#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
int num[maxn];
int sum[maxn];

int main()
{
	int n;
	while(cin >> n && n)
	{
		for(int i=1;i<=n;i++)
			cin >> num[i];
		int ans = 0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(num[i] > num[j] && sum[j] + num[i] > sum[i])
				{
					sum[i] = sum[j] + num[i];
					ans = max(ans,sum[i]);
				}
			}
		}
		cout << ans << endl;
	}	
	return 0;
 } 
