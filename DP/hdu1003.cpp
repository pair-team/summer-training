#include <bits/stdc++.h>

using namespace std;

int num[100005];

int main()
{
	int n;
	cin >> n;
	for(int t=1;t<=n;t++)
	{
		printf("Case %d:\n",t);
		int tmp;
		cin >> tmp;
		num[0] = 0;
		int cnt = 0;
		int ans = -1005;
		int s = 0, e=0;
		for(int i=1;i<=tmp;i++)
		{
			cin >> num[i];
			num[i] += num[i-1];
			if(num[i] - num[cnt] > ans)
			{
				ans = num[i] - num[cnt];
				e = i;
				s = cnt+1;
			}
			if(num[i] < num[cnt])
				cnt = i;
		}		
		
		printf("%d %d %d\n",ans,s,e);
		if(t!=n)
			cout << endl;
	}
	return 0;
}
