#include <bits/stdc++.h>

using namespace std;

int num[10005];

int main()
{
	int n;
	while(cin >> n && n)
	{
		for(int i=0;i<n;i++)
			cin >> num[i];
		
		int maxx = num[0];
		int s = 0,e = 0;
		int cnt = 0;
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			sum += num[i];
			if(sum < 0)
			{
				sum = 0;
				cnt = i + 1;
			}
			else if(sum > maxx)
			{
				s = cnt;
				e = i;
				maxx = sum;
			}
		}
		
		if(maxx < 0)
		{
			maxx = 0;
			s = 0;
			e = n-1;
		}
		printf("%d %d %d\n",maxx,num[s],num[e]);
	}
	return 0;
}
