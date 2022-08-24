#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 8;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, T, stx, sty, edx, edy;
char g[N][N];
bool st[N][N];

void init()
{
	memset(st, 0, sizeof st);
	stx = sty = 0;
}
bool dfs(int x, int y, int step)
{
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	if(st[x][y] || g[x][y] == 'X') return false;
	if(abs(x - edx) + abs(y - edy) > T - step) return false;
	if((abs(x - edx) + abs(y - edy)) % 2 != (T - step) % 2) return false;
	
	if(step == T)
	{
		if(g[x][y] == 'D') return true;
		return false;
	}
	
	st[x][y] = true;
	for(int i = 0; i < 4; i ++)
	{
		int a = x + dx[i], b = y + dy[i];
		if(dfs(a, b, step + 1)) return true;
	}
	st[x][y] = false;
	return false;
}


int main()
{
//	freopen("data1.txt", "r", stdin);
	while(scanf("%d%d%d", &n, &m, &T) == 3, n != 0 || m != 0 || T != 0)
	{
		init();
		for(int i = 0; i < n; i ++) scanf("%s", g[i]);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(g[i][j] == 'S') stx = i, sty = j;
				else if(g[i][j] == 'D') edx = i, edy = j;
		
		if(dfs(stx, sty, 0)) puts("YES");
		else puts("NO");
	}
    
    return 0;
}
/*
可行性剪枝 1. 距离 2. 奇偶性 
*/
