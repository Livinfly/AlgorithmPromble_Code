#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, P = 1e6 + 7;

int len, nums[N];
int dp[N][2]; // i bits, 0 -> same, 1 -> diff

inline int mod(int x)
{
	return (x % P + P) % P;
}
inline int dfs(int n, bool is_diff, bool is_max)
{
	if(!n) return 1;
	if(!is_max && dp[n][is_diff] != -1) return dp[n][is_diff];
	
	int ans = 0, m = is_max ? nums[n] : nums[n] + 1;
	for(int i = 1; i <= m; i ++)
	{
		ans = mod(dfs(n - 1, i != nums[n - 1], i == nums[n - 1] && is_max));
	}
	
	
	if(!is_max) dp[n][is_diff] = ans;
	
	return ans;
}

int main()
{
	memset(dp, -1, sizeof dp);
	scanf("%d", &len);
	for(int i = len; i; i --) scanf("%d", &nums[i]);
    dfs(len, 1, 1);
    if(len == 1) puts("1");
    else printf("%d\n", mod(max(dp[len - 1][0], 1) + (nums[1] != nums[2])));
    
    for(int i = len; i >= 0; i --)
    	cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    
    return 0;
}
