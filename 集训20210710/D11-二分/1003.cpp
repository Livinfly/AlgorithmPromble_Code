#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL K;
int a[N], b[N];

bool check(int mid)
{
	LL cnt = 0;
	for(int i = 0, j = m - 1; i < n && j >= 0;) // 跑i，记与i成对的j的个数 //j >= 0..
	{
		if(a[i] + b[j] <= mid) 
		{
			cnt += j + 1;
			i ++;
		}
		else j --;
	}
	return cnt >= K; // mid要再组成的数组里面，一定会把mid自己数进去也就是要>= K 
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
	{
		scanf("%d%d%lld", &n, &m, &K);
		for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
		for(int i = 0; i < m; i ++) scanf("%d", &b[i]);
		sort(a, a + n); sort(b, b + m);
		
		int l = 1, r = 2e8;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = mid; // 满足条件 修改区间使mid 趋向不满足 
			else l = mid + 1;
		}
		printf("%d\n", r);
	}
	
	return 0;
}
/*
寻找第k小的数，转化为满足“k-1个在它前面”的数中的最小的数
即 <= x 的有 >= k-1 个数的最小的数
构造一个函数f(x)，表示有f(x)对数对满足a[i] + b[j] <= x
是直接二分x这个第k小的数的值qwq
000000000000111111111
            * 
*/
