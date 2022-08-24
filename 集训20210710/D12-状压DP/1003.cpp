#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 17, M = 1 << N, P = 1e9 + 7;

int n, m, cur;
int p[N];
LL f[2][M];
/*
轮廓线DP 
f[i][S] 第i行 S状态的方案数
向上/左填/留空 
*/
void prev_calu()
{
	for(int i = 1, j = 1; i < N; i ++, j *= 2) p[i] = j;
}

int main()
{
	prev_calu(); 
	int T; scanf("%d", &T);
	while(T --)
	{
		memset(f, 0, sizeof f);
		scanf("%d%d", &n, &m);
		if(n < m) swap(n, m);
		f[0][(1 << m) - 1] = 1; // 第0行填满，因为第一行不能向上填
		cur = 0; // 滚动数组 
		for(int i = 0; i < n; i ++) // 枚举第i行
			for(int j = 1; j <= m; j ++) // 当前在操作的列数 
			{
				cur ^= 1; // 关于轮廓线 !!!???
				memset(f[cur], 0, sizeof f[cur]);
				for(int S = 0; S < 1 << m; S ++) // i - 1行的状态 
				{
					// 向上填 1. 上一行没有填 2. i > 0 
					if((S & p[j]) == 0 && i > 0) f[cur][S | p[j]] = (f[cur][S | p[j]] + f[cur ^ 1][S]) % P;
					// 向左填 1. 上一行填了 2. 上一行左边填了 3. j > 0
					if((S & p[j]) && (S & p[j - 1]) == 0 && j > 1) f[cur][S | p[j - 1]] = (f[cur][S | p[j - 1]] + f[cur ^ 1][S]) % P;
					// 不填 1. 上一行填了
					if(S & p[j]) f[cur][S ^ p[j]] = (f[cur][S ^ p[j]] + f[cur ^ 1][S]) % P;
				}
			}
		printf("%lld\n", f[cur][(1 << m) - 1] % P);
	}
	
	return 0;
}
