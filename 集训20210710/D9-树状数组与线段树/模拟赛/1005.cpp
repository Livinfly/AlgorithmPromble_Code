#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n, k;
int f[N][N];
int g[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
	if(f[x][y]) return f[x][y];
	f[x][y] = g[x][y];
	
	for(int i = 1; i <= k; i ++)
		for(int j = 0; j < 4; j ++)
		{
			int a = x + dx[j] * i, b = y + dy[j] * i;
			if(g[a][b] <= g[x][y]) continue;
			if(a < 1 || a > n || b < 1 || b > n) continue;
			f[x][y] = max(f[x][y], dfs(a, b) + g[x][y]);
		}
	return f[x][y];
}

int main()
{
	while(scanf("%d%d", &n, &k) == 2, n != -1 || k != -1)
	{
		memset(f, 0, sizeof f);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				scanf("%d", &g[i][j]);
		
		cout << dfs(1, 1) << endl;
	}
	
	return 0;
}
