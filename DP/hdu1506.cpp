#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 100005;
LL h[maxn];
int l[maxn],r[maxn];

int main()
{
	int n;
	while(cin >> n && n)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> h[i];
			l[i] = i;
			r[i] = i;
		}
		h[n+1] = h[0] = -1;
		for(int i=1;i<=n;i++)
		{
			while(h[l[i]-1] >= h[i])
				l[i] = l[l[i]-1];
		}
		
		for(int i=n;i>=1;i--)
		{
			while(h[r[i]+1] >= h[i])
				r[i] = r[r[i]+1];
		}
		
		LL ans = 0;
		for(int i=1;i<=n;i++)
			ans = max(ans, (r[i]-l[i]+1)*h[i]);
		cout << ans << endl;
	}
	
	return 0;
}
