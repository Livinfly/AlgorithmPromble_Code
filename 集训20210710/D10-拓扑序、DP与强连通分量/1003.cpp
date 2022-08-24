#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, M = 2e5 + 10;

int idx, h[N], rh[N], ne[M * 2], ver[M * 2]; // *2 ·´±ß 
int n, m;
int tt, q[N], scc_cnt, id[N], siz[N];
bool st[N];

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
	q[++ tt] = u;
}
void dfs2(int u, int scc_cnt)
{
	st[u] = false;
	id[u] = scc_cnt;
	siz[scc_cnt] ++;
	for(int i = rh[u]; ~i; i = ne[i]) // rh!!!
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
		idx = tt = scc_cnt = 0;
		memset(h, -1, sizeof h);
		memset(rh, -1, sizeof rh);
		memset(id, 0, sizeof id);
		memset(siz, 0, sizeof siz);
		scanf("%d%d", &n, &m);
		while(m --)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(h, a, b);
			add(rh, b, a);
		}
		
		for(int i = 1; i <= n; i ++)
			if(!st[i]) dfs1(i);
		for(int i = tt; i; i --)
			if(st[q[i]]) dfs2(q[i], ++ scc_cnt); // q[] !!!
		
//		for(int i = 1; i <= n; i ++)
//			cout << i << ' ' << id[i] << endl;
		
		LL res = 0;
		for(int i = 1; i <= scc_cnt; i ++)
			res = res + (LL)siz[i] * (siz[i] - 1) / 2;
			
		printf("%lld\n", res);
	}
    
    return 0;
}
