#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int idx, h[N], ne[M], ver[M];
int n, Q;
int w[N];
int d[N], fa[N], son[N], siz[N]; // dfs1
int timestamp, dfn[N], trw[N], top[N]; // dfs2
struct Node
{
	int l, r;
	int sum;
	int has;
	int tag;
} tr[N << 2];

//--------读边-------------
void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
} 
//--------线段树----------- 
void update(Node &u, Node &l, Node &r)
{
	u.has = l.has + r.has;
}
void pushup(int u)
{
	update(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void lazydown(int u)
{
	if(tr[u].tag != -1)
	{
		int t = tr[u].tag;
		Node &l = tr[u << 1], &r = tr[u << 1 | 1];
		l.has = l.sum * t, l.tag = t;
		r.has = r.sum * t, r.tag = t;
		tr[u].tag = -1;
	}
}
void build(int u, int l, int r)
{
	if(l == r)
	{
		tr[u] = (Node){l, r, trw[r], 0, -1}; // trw[] 树上的编号是连续的!! 
	}
	else
	{
		tr[u] = (Node){l, r, 0, 0, -1};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
	}
}
void modify(int u, int l, int r, int c)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].has = tr[u].sum * c;
		tr[u].tag = c;
	}
	else
	{
		lazydown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(u << 1, l, r, c);
		if(r > mid) modify(u << 1 | 1, l, r, c);
		pushup(u);
	}
}
//--------预处理----------- 
void init()
{
	timestamp = idx = 0;
	memset(h, -1, sizeof h);
	memset(son, 0, sizeof son);
}
void dfs1(int u, int f, int depth)
{
	d[u] = depth;
	fa[u] = f;
	siz[u] = 1;
	int maxson = -1;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(v == f) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if(siz[v] > maxson) son[u] = v, maxson = siz[v];
	}
}
void dfs2(int u, int rtop)
{
	dfn[u] = ++ timestamp;
	trw[dfn[u]] = w[u];
	top[u] = rtop;
	if(!son[u]) return;
	dfs2(son[u], rtop);
	
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
//--------树剖-------------- 
void change_x2y(int x, int y)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y);
		modify(1, dfn[top[x]], dfn[x], 1);
		x = fa[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	modify(1, dfn[y], dfn[x], 1);
}
void steal_x(int x)
{
	modify(1, dfn[x], dfn[x], 0); // dfn!!!
}
void change_son(int x)
{
	modify(1, dfn[x], dfn[x] + siz[x] - 1, 1);
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
	{
		init();
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
		for(int i = 0; i < n - 1; i ++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b), add(b, a); 
		}
		
		dfs1(1, 0, 1);
		dfs2(1, 1);
		build(1, 1, n);
		
//		for(int i = 1; i <= n; i ++) cout << dfn[i] << endl;
//		cout << endl;
		
		scanf("%d", &Q);
		while(Q --)
		{
			int op, x, y;
			scanf("%d", &op);
			if(op == 1)
			{
				scanf("%d%d", &x, &y);
				change_x2y(x, y);
				printf("%d\n", tr[1].has);
			}
			else if(op == 2)
			{
				scanf("%d", &x);
				steal_x(x);
				printf("%d\n", tr[1].has);
			}
			else
			{
				scanf("%d", &x);
				change_son(x);
				printf("%d\n", tr[1].has);
			}
		}
	}
    
    return 0;
}
