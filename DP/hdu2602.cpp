#include <bits/stdc++.h>

using namespace std;

struct bone{
	int volumn;
	int value;
}b[1005];

int dp[1005];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,v;
		cin >> n >> v;
		for(int i=0;i<n;i++)
			cin >> b[i].value;
		for(int i=0;i<n;i++)
			cin >> b[i].volumn; 
		
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			for(int j=v;j>=b[i].volumn;j--)
			{
				dp[j] = max(dp[j],dp[j-b[i].volumn] + b[i].value);
			}
		
		cout << dp[v] << endl;
	}
	
	return 0;
 } 
