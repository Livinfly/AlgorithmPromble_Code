#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5e4 + 10, K = 17;

int idx, h[N], ne[N * 2], ver[N * 2];
int n, m, p;
int w[N], fa[N][K], d[N];
int q[N];
LL dw[N];

void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void bfs()
{
	int hh = 0, tt = 0;
	q[0] = 1, d[1] = 1;
	
	while(hh <= tt)
	{
		int t = q[hh ++];
		
		for(int i = h[t]; ~i; i = ne[i])
		{
			int v = ver[i];
			if(d[v]) continue;
			d[v] = d[t] + 1;
			
			fa[v][0] = t;
			for(int k = 1; k < K; k ++)
				fa[v][k] = fa[fa[v][k - 1]][k - 1];
			
			q[++ tt] = v;
		}
	}
}
int lca(int x, int y)
{
	if(d[x] < d[y]) swap(x, y);
	for(int k = K - 1; k >= 0; k --) // x -> y
		if(d[fa[x][k]] >= d[y]) x = fa[x][k];
	
	if(x == y) return x;
	
	for(int k = K - 1; k >= 0; k --) // togeter
		if(fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
	
	return fa[x][0];
}
LL dfs(int u)
{
	LL res = dw[u];
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(fa[u][0] == v) continue;
		res += dfs(v);
	}
	return res;
}

int main()
{
//	freopen("data1.txt", "r", stdin);
	while(scanf("%d%d%d", &n, &m, &p) == 3)
	{
		idx = 0;
		memset(h, -1, sizeof h);
		memset(fa, 0, sizeof fa);
		memset(dw, 0, sizeof dw);
		memset(d, 0, sizeof d);
		for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
		while(m --)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b), add(b, a);
		}
		bfs();
		while(p --)
		{
			char op[4];
			int x, y, c;
			scanf("%s", op);
			if(*op == 'I')
			{
				scanf("%d%d%d", &x, &y, &c);
				int anc = lca(x, y);
				dw[x] += c, dw[y] += c, dw[anc] -= c, dw[fa[anc][0]] -= c;
			}
			else if(*op == 'D')
			{
				scanf("%d%d%d", &x, &y, &c);
				int anc = lca(x, y);
				dw[x] -= c, dw[y] -= c, dw[anc] += c, dw[fa[anc][0]] += c;
			}
			else
			{
				scanf("%d", &x);
				printf("%lld\n", dfs(x) + w[x]);
			}
		}
	}
    
    return 0;
}
/*
树上差分 -> 操作3会超时 ono
*/
