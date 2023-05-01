#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 15, M = 1 << N;

int n;
int a[N], logg2[M];
bool st[M];
LL f[M]; 
// 状态为i的集合的方案数 状态也是表示选了没选
// f[S] = sum(f[S - T]) T是和为质数的S的子集

inline void prev_calu()
{
	for(int i = 1, j = 0; i < M; i *= 2, j ++) logg2[i] = j;
}
inline void init()
{
	memset(st, 0, sizeof st);
	memset(f, 0, sizeof f);
	f[0] = 1;
}
inline int lowbit(int x)
{
	return x & -x;
}
inline bool is_prime(int x)
{
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i ++)
		if(x % i == 0) return false;
	return true;
}
inline bool check(int s)
{
	int sum = 0;
	for(; s; s -= lowbit(s))
	{
		int x = logg2[lowbit(s)];
		sum += a[x];
	}
	return is_prime(sum);
}


int main()
{
	prev_calu();
	int T; scanf("%d", &T);
	while(T --)
	{
		init();
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
		
		for(int S = 0; S < 1 << n; S ++) // S的状态 
			for(int T = S; T; T = (T - 1) & S)
				if(!st[T] && check(T)) 
				{
					f[S] += f[S - T]; // 方案数转移到大的集合中 
					st[S - T] = true; // 方案数只记一次，记过就标记上 
				}
		
		printf("%lld\n", f[(1 << n) - 1]);
	}
	
	return 0;
}
