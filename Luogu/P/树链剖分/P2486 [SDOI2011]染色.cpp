#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N << 1;

int idx, h[N], ver[M], ne[M];
int n, m;
int w[N];
int d[N], fa[N], son[N], siz[N];
int timestamp, dfn[N], trw[N], top[N];
struct Node
{
	int l, r;
	int cnt;
	int tag;
} tr[N << 2];

void init()
{
	memset(h, -1, sizeof h);
}
// add_edge 
void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
// Segment Tree
void update(Node &u, Node &l, Node &r)
{
	u.cnt = l.cnt + r.cnt - (trw[l.r] == trw[r.l]);
	u.l = l.l, u.r = r.r; // 更像合并这两个区间，l，r更新是为了新区间的l和r 
}
void pushup(int u)
{
	update(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void lazydown(int u)
{
	if(tr[u].tag)
	{
		int c = tr[u].tag;
		Node &l = tr[u << 1], &r = tr[u << 1 | 1];
		trw[l.l] = trw[l.r] = c, l.cnt = 1, l.tag = c;
		trw[r.l] = trw[r.r] = c, r.cnt = 1, r.tag = c;
		tr[u].tag = 0;
	}
}
void build(int u, int l, int r)
{
	if(l == r) tr[u] = (Node){l, r, 1};
	else
	{
		tr[u] = (Node){l, r, 0, 0};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r, int c)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		trw[tr[u].l] = trw[tr[u].r] = c = c;
		tr[u].cnt = 1;
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
Node query(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r) return tr[u];
	else 
	{
		lazydown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		Node left = (Node){0}, right = (Node){0}, res = tr[u];
		if(l <= mid) left = query(u << 1, l, r);
		if(r > mid) right = query(u << 1 | 1, l, r);
		if(left.l == 0) res = right;
		else if(right.l == 0) res = left;
		else update(res, left, right);
		return res;
	}
}
// prev_calu
void dfs1(int u, int f, int depth)
{
	d[u] = depth;
	fa[u] = f;
	siz[u] = 1;
	son[u] = 0;
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
void change_x2y(int x, int y, int c)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y);
		modify(1, dfn[top[x]], dfn[x], c);
		x = fa[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	modify(1, dfn[y], dfn[x], c);
}
int cnt_x2y(int x, int y)
{
	Node res, a, b, t;
	res = a = b = t = (Node){0};
	int k = 1;
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y), swap(a, b), k ^= 1;
		t = query(1, dfn[top[x]], dfn[x]);
		if(a.cnt == 0) a = t;
		else update(a, t, a);
		x = fa[top[x]];
	}
	if(d[x] < d[y]) swap(x, y), swap(a, b);
	t = query(1, dfn[y], dfn[x]);
	if(a.cnt == 0) a = t;
	else update(a, t, a);
	if(b.cnt == 0) return a.cnt;
	if(a.cnt == 0) return b.cnt;
	if(!k) swap(a, b);
	swap(a.l, a.r);
	update(res, a, b);
	return res.cnt;
}

int main()
{
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	for(int i = 0; i < n - 1; i ++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs1(1, -1, 1);
	dfs2(1, 1);
	build(1, 1, n);
	while(m --)
	{
		int a, b, c;
		char op[2];
		scanf("%s", op);
		if(*op == 'C')
		{
			scanf("%d%d%d", &a, &b, &c);
			change_x2y(a, b, c);
		}
		else
		{
			scanf("%d%d", &a, &b);
			printf("%d\n", cnt_x2y(a, b));
		}
	}
	
	return 0;
}
/*
参照
hs_black
更新时间：2019-10-10 00:08:18 
*/ 
