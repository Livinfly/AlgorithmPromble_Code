#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL a[N], b[N];

bool check(int mid)
{
	LL cnt = mid;
	for(int i = 0; i < mid; i ++) b[i] = a[i];
	for(int i = mid, j = 0; i < n; i ++)
	{
		if(a[i] >= 2 * b[j])
		{
			b[j] = a[i];
			j ++;
			j %= mid;
			cnt ++;
		}
	}
	if((LL)mid * m <= cnt) return true;
	return false;
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i ++)
			scanf("%lld", &a[i]);
		sort(a, a + n);
		int l = 0, r = n; // 可以叠的塔数量是[0, n]，其实还可以更精确一点 
		while(l < r)
		{
			int mid = l + r + 1 >> 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", r);
	}
	
	return 0;
}
/*
二分 叠x座塔 
*/
