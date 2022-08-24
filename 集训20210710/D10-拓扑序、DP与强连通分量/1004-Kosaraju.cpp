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
int scc_cnt, id[N], scc_w[N];
bool st[N];

void init()
{
	idx = top = scc_cnt = 0;
	memset(h, -1, sizeof h);
	memset(rh, -1, sizeof rh);
	memset(sh, -1, sizeof sh);
	memset(scc_w, 0, sizeof scc_w);
}
void add(int h[], int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs1(int u)
{
	st[u] = true;
	for(int i = h[u]; ~i; i = ne[i])
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
	scc_w[scc_cnt] = max(scc_w[scc_cnt], w[u]);
	
	for(int i = rh[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(st[v]) dfs2(v, scc_cnt);
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
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
		
//		for(int i = 1; i <= n; i ++)
//			cout << i << ' ' << id[i] << endl;
//		cout << endl;
		
		for(int i = 1; i <= n; i ++)
			for(int j = h[i]; ~j; j = ne[j])
			{
				int v = ver[j];
				int a = id[i], b = id[v];
				if(a != b)
				{
					add(sh, b, a); // 反图 
				}
			}
		for(int i = scc_cnt; i; i --)
			for(int j = sh[i]; ~j; j = ne[j])
			{
				int v = ver[j];
				scc_w[v] = max(scc_w[v], scc_w[i]);
			}
		for(int i = 1; i <= n; i ++)
			printf("%d\n", scc_w[id[i]]);
	}
    
    return 0;
}
/*
先正图再反图，1 -> scc_cnt 拓扑序
先反图再正图, scc_cnt -> 1 拓扑序 
*/
