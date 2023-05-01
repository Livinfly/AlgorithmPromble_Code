#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int top, stk[N];
bool in_stk[N];
int idx, h[N], sh[N], ne[M * 2], ver[M * 2];
int n, m;
int w[N];
int timestamp, dfn[N], low[N];
int scc_cnt, id[N], scc_w[N], scc_f[N];

void init()
{
	idx = timestamp = scc_cnt = 0;
	memset(h, -1, sizeof h);
	memset(sh, -1, sizeof sh);
	memset(dfn, 0, sizeof dfn);
	memset(scc_w, 0, sizeof scc_w);
	memset(scc_f, 0, sizeof scc_f);
}
void add(int h[], int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void tarjan(int u)
{
	stk[++ top] = u, in_stk[u] = true;
	dfn[u] = low[u] = ++ timestamp;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(in_stk[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u])
	{
		int v;
		++ scc_cnt;
		do
		{
			v = stk[top --], in_stk[v] = false;
			id[v] = scc_cnt, scc_w[scc_cnt] = max(scc_w[scc_cnt], w[v]);
		} while(u != v);
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
		while(m -- )
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(h, a, b);
		}
		for(int i = 1; i <= n; i ++)
			if(!dfn[i]) tarjan(i);
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
		for(int i = 1; i <= scc_cnt; i ++) // 反向的拓扑序 
		{
			scc_f[i] = max(scc_f[i], scc_w[i]);
			for(int j = sh[i]; ~j; j = ne[j])
			{
				int v = ver[j];
				scc_f[v] = max(scc_f[v], scc_f[i]);
			}
		}
		for(int i = 1; i <= n; i ++)
			printf("%d\n", scc_f[id[i]]);
	}
    
    return 0;
}
