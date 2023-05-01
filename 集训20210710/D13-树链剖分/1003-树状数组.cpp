#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e4 + 10, M = N * 2;

int idx, h[N], ne[M], ver[M];
int n, m, p;
int w[N];
int d[N], fa[N], siz[N], son[N];
int timestamp, dfn[N], top[N];
int tr[N]; 

// 加边 
void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
// 树状数组
int lowbit(int x)
{
	return x & -x;
}
void add_tr(int x, int c)
{
	for(; x <= n; x += lowbit(x)) tr[x] += c;
}
int sum_tr(int x)
{
	int res = 0;
	for(; x; x -= lowbit(x)) res += tr[x];
	return res;
}

// 预处理 ------------------------
void dfs1(int u, int f, int depth)
{
	d[u] = depth; // d
	fa[u] = f; // fa
	siz[u] = 1; // siz
	int maxson = -1; // 记录编号
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
//	trw[dfn[u]] = w[u];
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
// 树剖 
void add_x2y(int x, int y, int c)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y); // x - deeper, d!!!
//		modify(1, dfn[top[x]], dfn[x], c); // dfn!!!
		add_tr(dfn[top[x]], c), add_tr(dfn[x] + 1, -c);
		x = fa[top[x]]; // top !!!
	}
	if(d[x] < d[y]) swap(x, y);
//	modify(1, dfn[y], dfn[x], c);
	add_tr(dfn[y], c), add_tr(dfn[x] + 1, -c);
}
int sum_x2y(int x, int y)
{
	int res = 0;
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]]) swap(x, y);
//		res = res + query(1, dfn[top[x]], dfn[x]);
		res = res + sum_tr(dfn[x]) - sum_tr(dfn[top[x]] - 1);
		x = fa[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
//	res = res + query(1, dfn[y], dfn[x]);
	res = res + sum_tr(dfn[x]) - sum_tr(dfn[y] - 1);
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("data1.txt", "r", stdin);
	while(cin >> n >> m >> p)
	{
		idx = timestamp = 0;
		memset(h, -1, sizeof h);
		memset(d, 0, sizeof d);
		memset(fa, 0, sizeof fa);
		memset(tr, 0, sizeof tr);
		memset(son, 0, sizeof son); // forget !!!!!!!!!!!!!!!!!!!!!!!
		
		for(int i = 1; i <= n; i ++) cin >> w[i];
		for(int i = 0; i < m; i ++)
		{
			int a, b;
			cin >> a >> b;
			add(a, b), add(b, a);
		}
		
		dfs1(1, 0, 1);
		dfs2(1, 1);
//		build(1, 1, n);
		
		while(p --)
		{
			char op[2];
			int x, y, z;
			cin >> op;
			if(*op == 'I')
			{
				cin >> x >> y >> z;
				add_x2y(x, y, z);
			}
			else if(*op == 'D')
			{
				cin >> x >> y >> z;
				add_x2y(x, y, -z);
			}
			else
			{
				cin >> x;
				cout << sum_tr(dfn[x]) + w[x] << endl;
			}
		}
	}
	
    return 0;
}
