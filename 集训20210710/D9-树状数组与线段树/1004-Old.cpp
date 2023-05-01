#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int w[N];
struct Node
{
    int l, r;
    int maxn;
} tr[N * 4];

void push_up(int u)
{
    tr[u].maxn = max(tr[u << 1].maxn, tr[u << 1 | 1].maxn);
}
void build(int u, int l, int r)
{
    if(l == r) tr[u] = (Node){l, r, w[r]};
    else
    {
        tr[u] = (Node){l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}
void modify(int u, int x, int c)
{
    if(tr[u].l == x && tr[u].r == x) tr[u].maxn = c;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, c);
        if(x > mid) modify(u << 1 | 1, x, c);
        push_up(u);
    }
}
int query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].maxn;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if(l <= mid) res = max(res, query(u << 1, l, r));
        if(r > mid) res = max(res, query(u << 1 | 1, l, r));
        return res;
    }
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(tr, 0, sizeof tr);
	    for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	    
	    build(1, 1, n);
	    
	    while(m --)
	    {
	        int a, b;
	        char op[2];
	        scanf("%s%d%d", op, &a, &b);
	        if(*op == 'Q')
	        {
	            if(a > b) swap(a, b);
	            printf("%d\n", query(1, a, b));
	        }
	        else
	        {
	            if(w[a] < b) 
	            {
	                w[a] = b;
	                modify(1, a, b);
	            }
	        }
	    }
	}
    
    return 0;
}
