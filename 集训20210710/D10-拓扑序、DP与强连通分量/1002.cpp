#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110, P = 10000;

int n, m;
int g[N][N], dp[N][N];

void init()
{
	memset(dp, 0, sizeof dp);
	dp[1][1] = 1;
}
//int dfs(int x, int y)
//{
//	if(x < 1 || x > n || y < 1 || y > m) return 0;
//	
//	for(int i = 1; i <= g[x][y]; i ++)
//	{
//		for(int j = 0; j <= i; j ++)
//		{
//			int a = x + j, b = y + i - j;
//			dp[a][b] = dp[a][b] + dp[x][y];
//		}
//	}
//	
//	return dp[x][y];
//}

int main()
{
	int T; scanf("%d", &T);
    while(T --)
    {
    	init();
    	scanf("%d%d", &n, &m);
    	for(int i = 1; i <= n; i ++) 
    		for(int j = 1; j <= m; j ++)
    			scanf("%d", &g[i][j]);
    	
//    	dfs(1, 1);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				for(int k = 1; k <= g[i][j]; k ++)
					for(int z = 0; z <= k; z ++)
					{
						int a = i + z, b = j + k - z;
						if(a > n || b > m) continue;
						dp[a][b] = (dp[a][b] + dp[i][j]) % P;
					}
    	
    	printf("%d\n", dp[n][m]);
	}
    return 0;
}
