#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int idx, h[N], rh[N], sh[N], ne[M * 3], ver[M * 3];
int n, m;
int w[N];
int stk[N], top;
int scc_cnt, id[N], scc_w[N], f[N];
bool st[N];

void init()
{
	idx = top = scc_cnt = 0;
	memset(h, -1, sizeof h);
	memset(rh, -1, sizeof rh);
	memset(sh, -1, sizeof sh);
}
void add(int h[], int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs1(int u)
{
	st[u] = true;
	for(int i = rh[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(!st[v]) dfs1(v);
	}
	stk[++ top] = u;
}
void dfs2(int u, int scc_cnt)
{
	st[u] = false;
	id[u] = scc_cnt;
	scc_w[scc_cnt] += w[u];
	
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(st[v]) dfs2(v, scc_cnt);
	}
}

int main()
{
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	while(m --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(h, a, b);
		add(rh, b, a);
	}
	for(int i = 1; i <= n; i ++)
		if(!st[i]) dfs1(i);
	for(int i = n; i; i --) 
		if(st[stk[i]]) dfs2(stk[i], ++ scc_cnt); // stk stk!!
	
	for(int i = 1; i <= n; i ++)
		for(int j = h[i]; ~j; j = ne[j])
		{
			int v = ver[j];
			int a = id[i], b = id[v];
			if(a != b) add(sh, a, b);
		}
	for(int i = scc_cnt; i; i --)
	{
		if(!f[i]) f[i] = scc_w[i];
		for(int j = sh[i]; ~j; j = ne[j])
		{
			int v = ver[j];
			f[v] = max(f[v], f[i] + scc_w[v]);
		}
	}
	
	int res = 0;
	for(int i = 1; i <= scc_cnt; i ++)
		res = max(res, f[i]);
	
	printf("%d\n", res);
    
    return 0;
}
