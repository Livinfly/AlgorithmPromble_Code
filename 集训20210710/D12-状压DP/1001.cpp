#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 17, M = 1 << N;

int n;
int a[N], p[N], ones[M];
LL f[M][N]; // i表示确定座位的人的编号，j表示目前最后一位是谁 

void init()
{
	memset(f, -0x3f, sizeof f); // f可能是负的，要初始化为-INF 
}

int main()
{
	for(int i = 0; i < 1 << 17; i ++) 
		ones[i] = ones[i >> 1] + (i & 1);
	int T; scanf("%d", &T);
	for(int Case = 1; Case <= T; Case ++)
	{
		init();
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d%d", &a[i], &p[i]);
		
		for(int i = 0; i < n; i ++) 
			if(p[i] == -1 || p[i] == 0) f[1 << i][i] = 0;
		
		for(int i = 0; i < 1 << n; i ++) // 状态 
			for(int j = 0; j < n; j ++)	// 末位 
				if(f[i][j] >= -1e18) // 当前状态合法 (初始化为f[][] = -4e18)
					for(int k = 0; k < n; k ++) // 枚举下一个人放谁 
						if(((i >> k & 1) == 0) && (p[k] == -1 || ones[i] == p[k])) // 1. 这个人没被放过 2. 位置可坐 
							f[i + (1 << k)][k] = max(f[i + (1 << k)][k], f[i][j] + a[j] * a[k]);
		LL res = -1e18;
		for(int i = 0; i < n; i ++) // 结果最大末位1~n都有可能 
			res = max(res, f[(1 << n) - 1][i]);
		
		printf("Case #%d:\n", Case);
		printf("%lld\n", res);
	}
	
	return 0;
}
