#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL n, m, maxn, sum;
LL a[N];

LL check(LL mid)
{
	LL cnt = 1, s = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(s + a[i] <= mid) s += a[i];
		else
		{
			s = a[i];
			cnt ++;
		}
	}
	
	return cnt;
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
	{
		maxn = sum = 0;
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; i ++) 
		{
			scanf("%lld", &a[i]);
			maxn = max(maxn, a[i]);
			sum += a[i];
		}
		LL l = maxn, r = sum;
		while(l < r)
		{
			LL mid = l + r >> 1; // LL
			if(check(mid) <= m) r = mid;
			else l = mid + 1;
		}
		printf("%lld\n", r);
	}
	
	return 0;
}
/*
二分答案，最大的数字和 
check(x) 和为x 分的最少的段数 
*/
