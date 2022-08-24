#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int idx, h[N], ne[N], ver[N];
int n, Q;
int d[N], fa[N], siz[N], son[N];
int timestamp, dfn[N], top[N]; // trw[N];
struct Node
{
	int l, r;
	int has;
	int cnt;
	int tag;
} tr[N << 2];

//-----add_edge-------
void add(int a, int b)
{
	ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
//-----Segment_Tree
void pushup(int u)
{
	tr[u].has = tr[u << 1].has + tr[u << 1 | 1].has;
}
void lazydown(int u)
{
	if(tr[u].tag != -1)
	{
		int t = tr[u].tag;
		Node &l = tr[u << 1], &r = tr[u << 1 | 1];
		l.has = l.cnt * t, l.tag = t;
		r.has = r.cnt * t, r.tag = t;
		tr[u].tag = -1;
	}
}
void build(int u, int l, int r)
{
	if(l == r) tr[u] = (Node){l, r, 0, 1, -1};
	else
	{
		tr[u] = (Node){l, r, 0, 0, -1};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
	}
}
void modify(int u, int l, int r, int c)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].has = tr[u].cnt * c;
		tr[u].tag = c;
	}
	else
	{
		lazydown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(u << 1, l, r, c); // mistake!!!
		if(r > mid) modify(u << 1 | 1, l, r, c); // mistake!!!
		pushup(u);
	}
}
//----prev_solve-----
void init()
{
	idx = timestamp = 0;
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
//	trw[dfn[u]] = w[u];
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
void set_x2y(int x, int y)
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
void reset_son(int x)
{
	modify(1, dfn[x], dfn[x] + siz[x] - 1, 0);
}

int main()
{
	init();
	scanf("%d", &n);
	for(int i = 1; i < n; i ++)
	{
		int a;
		scanf("%d", &a);
		add(a, i);
	}
    
    dfs1(0, -1, 1);
    dfs2(0, 0);
    build(1, 1, n);
    
//    for(int i = 0; i < n - 1; i ++)
//    	cout << i << ' ' << dfn[i] << endl;
    
    scanf("%d", &Q);
    while(Q --)
    {
    	int x;
    	char op[10];
    	scanf("%s%d", op, &x);
    	if(*op == 'i')
    	{
    		int res1 = tr[1].has;
    		set_x2y(0, x);
    		int res2 = tr[1].has;
    		printf("%d\n", abs(res1 - res2));
		}
		else
		{
			int res1 = tr[1].has;
    		reset_son(x);
    		int res2 = tr[1].has;
    		printf("%d\n", abs(res1 - res2));
		}
	}
    
    return 0;
}
/*
op1: 把根节点到x的状态更新为1
op2: 把以x为根的子树清空（包括x） 
*/
