#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 20, P = 1e9 + 7;

LL len, nums[N];
LL l, r;
LL power10[N];
struct rec
{
	LL cnt, sum, sq_sum;
} dp[N][7][7];

void init()
{
	power10[0] = 1;
	for(int i = 1; i < N; i ++) power10[i] = power10[i - 1] * 10 % P;
	
	memset(dp, -1, sizeof dp);
//	for(int i = 0; i < N; i ++)
//		for(int j = 0; j < 7; j ++)
//			for(int k = 0; k < 7; k ++)
//				dp[i][j][k].cnt = -1;
}
rec dfs(LL n, int ss_mod, int ts_mod, bool is_max) // single_sum, team_sum
{
	if(!n)
	{
		rec t;
		t = (rec){ss_mod && ts_mod, 0, 0}; //mark
		return t;
	}
	if(!is_max && ~dp[n][ss_mod][ts_mod].cnt) return dp[n][ss_mod][ts_mod];
	
	rec ans = (rec){0, 0, 0}, t;
	int m = is_max ? nums[n] : 9;
	for(int i = 0; i <= m; i ++)
	{
		if(i == 7) continue;
		t = dfs(n - 1, (ss_mod + i) % 7, (ts_mod * 10 + i) % 7, is_max && i == m);
		
		ans.cnt = (ans.cnt + t.cnt) % P;
		
		ans.sum = (ans.sum + (t.sum + i * power10[n - 1] % P * t.cnt % P) % P) % P;
		
		ans.sq_sum = (ans.sq_sum + ((t.cnt * i % P * i % P * power10[n - 1] % P * power10[n - 1] % P + t.sq_sum) % P + 2 * i * power10[n - 1] % P * t.sum % P) % P) % P;
	}
	
	if(!is_max) dp[n][ss_mod][ts_mod] = ans;
	return ans;
}
LL solve(LL n)
{
	len = 0;
	while(n) nums[++ len] = n % 10, n /= 10;
	
	return dfs(len, 0, 0, true).sq_sum % P;
}

int main()
{
	init();
	int T; cin >> T;
	while(T --)
	{
		cin >> l >> r;
		cout << ((solve(r) - solve(l - 1)) % P + P) % P << endl;
	}
	
	return 0;
}
/*
1. 不含7
2. cur的个个位相加不是7的倍数 
3. 整个数不是7的倍数（就每位都*10 + i过去就好了！！？）
最后返回的是余数为 0 0 即可 

1. cnt 转移：直接加
2. sum 转移：ans.sum += t.sum + i * power10[n] * t.cnt
3. sq_sum 转移：ans.sq_sum += cnt*(i * power10[n])^2 + t.sq_sum + 2 * i * power10[n] * b.sum

推导过程：

先从单个的 sum, sq_sum 开始
再到整个，把i合并同类项，得出式子 
*/
