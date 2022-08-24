#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 20;

int nums[N], len;
LL n;
LL dp[N][2]; // n位，不含49个数 

LL dfs(LL n, bool is_4, bool is_max)
{
	if(!n) return 1;
	if(!is_max && dp[n][is_4] != -1) return dp[n][is_4];
	
	LL ans = 0;
	int m = is_max ? nums[n] : 9;
	for(int i = 0; i <= m; i ++)
		if(!(is_4 && i == 9)) ans += dfs(n - 1, i == 4, is_max && i == m);
	
	if(!is_max) dp[n][is_4] = ans;
	
	return ans;
}
LL solve(LL n)
{
	len = 0;
	while(n) nums[++ len] = n % 10, n /= 10;
	return dfs(len, false, true) - 1;
}


int main()
{
	memset(dp, -1, sizeof dp);
	int T; cin >> T;
	while(T --)
	{
		cin >> n;
		cout << n - solve(n) << endl;
	}
	
	return 0;
}
