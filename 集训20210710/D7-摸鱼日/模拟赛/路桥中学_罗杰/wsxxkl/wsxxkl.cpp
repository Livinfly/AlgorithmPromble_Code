#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, dh, q, lastp, lasth;
int h[N], p[N];
int id[N];
struct rec
{
	int h, p;
	bool operator < (const rec &o)const
	{
		return p < o.p;
	}
}xrz[N];

int main()
{
	freopen("wsxxkl.in", "r", stdin);
	freopen("wsxxkl.out", "w", stdout);
	scanf("%d%d%d", &n, &dh, &q);
	for(int i = 1; i <= n; i ++) scanf("%d%d", &xrz[i].h, &xrz[i].p);
	
	sort(xrz + 1, xrz + n + 1);
	
	while(q --)
	{
		bool flag = true;
		int l, r;
		scanf("%d%d", &l, &r);
		for(int i = 1; i <= n; i ++)
			if(xrz[i].p >= l && xrz[i].p <= r)
			{
//				if(xrz[i].p - lastp >= 2 * dh) lasth = dh;
				if(xrz[i].h <= dh) 
				{
					flag = false;
					break;
				}
			}
		if(flag) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
