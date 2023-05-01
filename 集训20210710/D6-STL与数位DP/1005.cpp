#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10;

int l, r;
int len, nums[N];
int dp[N][2];

int dfs(int n, bool is_6, bool is_max)
{
	if(!n) return 1;
	if(!is_max && dp[n][is_6] != -1) return dp[n][is_6];
	
	int m = is_max ? nums[n] : 9;
	int ans = 0;
	for(int i = 0; i <= m; i ++)
		if(i != 4 && !(is_6 && i == 2)) 
			ans += dfs(n - 1, i == 6, is_max && i == m);
	
	if(!is_max) dp[n][is_6] = ans;
	return ans;
}
int solve(int n)
{
	len = 0;
	while(n) nums[++ len] = n % 10, n /= 10;
	return dfs(len, false, true);
}

int main()
{
	memset(dp, -1, sizeof dp);
	while(scanf("%d%d", &l, &r) == 2, l || r)
	{
		printf("%d\n", solve(r) - solve(l - 1));
	}
	
	return 0;
}
