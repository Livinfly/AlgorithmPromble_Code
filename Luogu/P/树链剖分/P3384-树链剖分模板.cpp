#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int idx, h[N], ne[M], ver[M];
int n, m, root, P;
int w[N];
int d[N], fa[N], siz[N], son[N];
int timestamp, dfn[N], trw[N], top[N];
struct Node
{
	int l, r;
	int sum;
	int tag;
} tr[N * 4];

// ¼Ó±ß 
void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
// Ïß¶ÎÊ÷ 
void updata(Node &u, Node &l, Node &r)
{
	u.sum = (l.sum + r.sum) % P;
}
void pushup(int u)
{
	updata(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void lazydown(int u)
{
	if(tr[u].tag)
	{
		Node &l = tr[u << 1], &r = tr[u << 1 | 1];
		l.sum = (l.sum + (l.r - l.l + 1) * tr[u].tag % P) % P, l.tag += tr[u].tag;
		r.sum = (r.sum + (r.r - r.l + 1) * tr[u].tag % P) % P, r.tag += tr[u].tag;
		tr[u].tag = 0;
	}
}
void build(int u, int l, int r)
{
	if(l == r)
	{
		tr[u] = (Node){l, r, trw[r] % P, 0}; // trw !!! no w!!!
	}
	else
	{
		tr[u] = (Node){l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r, int c)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * c % P) % P;
		tr[u].tag += c;
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
int query(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum % P;
	else
	{
		lazydown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		int res = 0;
		if(l <= mid) res = (res + query(u << 1, l, r)) % P;
		if(r > mid) res = (res + query(u << 1 | 1, l, r)) % P;
		return res;
	}
}
// Ô¤´¦Àí ------------------------
void dfs1(int u, int f, int depth)
{
	d[u] = depth; // d
	fa[u] = f; // fa
	siz[u] = 1; // siz
	int maxson = -1; // ¼ÇÂ¼±àºÅ
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(v == f) continue; // No back
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if(siz[v] > maxson) son[u] = v, maxson = siz[v];
	}
}
void dfs2(int u, int rtop) // real-top
{
	dfn[u] = ++ timestamp;
	trw[dfn[u]] = w[u];
	top[u] = rtop;
	
	if(!son[u]) return; // no son back
	dfs2(son[u], rtop);
	
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = ver[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v); // every son has a chain
	}
}
// Ê÷ÆÊ 
void add_x2y(int x, int y, int c)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y); // x - deeper, d!!!
		modify(1, dfn[top[x]], dfn[x], c); // dfn!!!
		x = fa[top[x]]; // top !!!
	}
	if(d[x] < d[y]) swap(x, y);
	modify(1, dfn[y], dfn[x], c);
}
int sum_x2y(int x, int y)
{
	int res = 0;
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y);
		res = (res + query(1, dfn[top[x]], dfn[x]) % P) % P;
		x = fa[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	res = (res + query(1, dfn[y], dfn[x]) % P) % P;
	return res;
}
void add_son(int x, int c)
{
	modify(1, dfn[x], dfn[x] + siz[x] - 1, c);
}
int sum_son(int x)
{
	int res = 0;
	res = query(1, dfn[x], dfn[x] + siz[x] - 1) % P;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("data1.txt", "r", stdin);
	memset(h, -1, sizeof h);
	cin >> n >> m >> root >> P;
	for(int i = 1; i <= n; i ++) cin >> w[i];
	for(int i = 0; i < n - 1; i ++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs1(root, 0, 1);
	dfs2(root, root);
	build(1, 1, n);
	
	while(m --)
	{
		int op, x, y, z;
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y >> z;
			add_x2y(x, y, z);
		}
		else if(op == 2)
		{
			cin >> x >> y;
			cout << sum_x2y(x, y) << endl;
		}
		else if(op == 3)
		{
			cin >> x >> z;
			add_son(x, z);
		}
		else
		{
			cin >> x;
			cout << sum_son(x) << endl;
		}
	}
    
    return 0;
}
