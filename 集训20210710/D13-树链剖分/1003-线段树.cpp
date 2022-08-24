#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int idx, h[N], ne[M], ver[M];
int n, m, p;
int w[N];
int d[N], fa[N], siz[N], son[N];
int timestamp, dfn[N], trw[N], top[N];
struct Node
{
    int l, r;
    int sum;
    int tag;
} tr[N * 4];

// &#188;車㊣&#223; 
void add(int a, int b)
{
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
// &#207;&#223;&#182;&#206;那¯ 
void updata(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
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
        l.sum = l.sum + (l.r - l.l + 1) * tr[u].tag, l.tag += tr[u].tag;
        r.sum = r.sum + (r.r - r.l + 1) * tr[u].tag, r.tag += tr[u].tag;
        tr[u].tag = 0;
    }
}
void build(int u, int l, int r)
{
    if(l == r)
    {
        tr[u] = (Node){l, r, trw[r], 0}; // trw !!! no w!!!
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
        tr[u].sum = tr[u].sum + (tr[u].r - tr[u].l + 1) * c;
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
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else
    {
        lazydown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if(l <= mid) res = res + query(u << 1, l, r);
        if(r > mid) res = res + query(u << 1 | 1, l, r);
        return res;
    }
}
// &#212;∟∩|角赤 ------------------------
void dfs1(int u, int f, int depth)
{
    d[u] = depth; // d
    fa[u] = f; // fa
    siz[u] = 1; // siz
    int maxson = -1; // &#188;&#199;&#194;&#188;㊣角o&#197;
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
// 那¯&#198;那 
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
        res = res + query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(d[x] < d[y]) swap(x, y);
    res = res + query(1, dfn[y], dfn[x]);
    return res;
}
void add_son(int x, int c)
{
    modify(1, dfn[x], dfn[x] + siz[x] - 1, c);
}
int sum_son(int x)
{
    int res = 0;
    res = query(1, dfn[x], dfn[x] + siz[x] - 1);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
//    freopen("data1.txt", "r", stdin);
    while(cin >> n >> m >> p)
    {
        idx = timestamp = 0;
        memset(h, -1, sizeof h);
        memset(d, 0, sizeof d);
        memset(fa, 0, sizeof fa);
        memset(son, 0, sizeof son); // !!!!!!!!!!!!
        for(int i = 1; i <= n; i ++) cin >> w[i];
        for(int i = 0; i < m; i ++)
        {
            int a, b;
            cin >> a >> b;
            add(a, b), add(b, a);
        }
        
        dfs1(1, 0, 1);
        dfs2(1, 1);
        build(1, 1, n);
        
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
                cout << query(1, dfn[x], dfn[x]) << endl;
            }
        }
    }
    
    return 0;
}
