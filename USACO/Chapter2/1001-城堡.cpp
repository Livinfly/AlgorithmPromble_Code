#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 55;

char dir[4] = {'W', 'N', 'E', 'S'};
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int n, m, cnt, maxn1, maxn2, ansx, ansy, ansd;
int g[N][N], siz[N * N], id[N][N]; // cnt 最大有N * N个！！ 
bool st[N][N];

void dfs1(int x, int y)
{
	st[x][y] = true;
	id[x][y] = cnt;
	siz[cnt] ++;
	for(int i = 0, j = 1; i < 4; i ++, j *= 2)
	{
		if((g[x][y] / j) % 2 == 0)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a < 1 || a > n || b < 1 || b > m) continue;
			if(st[a][b]) continue;
			dfs1(a, b);
		}
	}
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			scanf("%d", &g[i][j]);
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(!st[i][j]) 
			{
				cnt ++;
				dfs1(i, j);
			}
	
	for(int i = 1; i <= cnt; i ++)
		maxn1 = max(maxn1, siz[i]);
	
//	for(int i = 1; i <= cnt; i ++)
//		cout << siz[i] << endl; 
	
	for(int y = 1; y <= m; y ++) // y
		for(int x = n; x; x --) // x
		{
			for(int i = 1, j = 2; i <= 2; i ++, j *= 2)
			{
				if((g[x][y] / j) % 2 == 1)
				{
					int a = x + dx[i], b = y + dy[i];
					if(a < 1 || a > n || b < 1 || b > m) continue;
					if(id[x][y] == id[a][b]) continue; // 本就是同一个房间 不能算 
					if(siz[id[x][y]] + siz[id[a][b]] > maxn2)
					{
//						cout << siz[id[x][y]] << ' ' << siz[id[a][b]] << endl;
						maxn2 = siz[id[x][y]] + siz[id[a][b]];
						ansx = x, ansy = y;
						ansd = i;
					}
				}
			}
		}
	
	printf("%d\n%d\n%d\n%d %d %c\n", cnt, maxn1, maxn2, ansx, ansy, dir[ansd]);
	
	return 0;
}
/*
求两次dfs
1. 求出问题1，问题2，并记录下每个方格对应的最大面积
2. 从左下角枚举拆哪个墙，更新答案 
*/
