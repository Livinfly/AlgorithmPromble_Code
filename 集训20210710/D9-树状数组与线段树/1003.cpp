#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, m;
struct Seg
{
	int l, r;
	int sum;
	int tag;
} tr[N * 4];

void push_up(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void lazydown(int u)
{
	if(tr[u].tag)
	{
		Seg &l = tr[u << 1], &r = tr[u << 1 | 1];
		l.sum = (l.r - l.l + 1) * tr[u].tag, l.tag = tr[u].tag;
		r.sum = (r.r - r.l + 1) * tr[u].tag, r.tag = tr[u].tag;
		tr[u].tag = 0;
	}
}
void build(int u, int l, int r)
{
	if(l == r) tr[u] = (Seg){l, r, 1, 0};
	else
	{
		tr[u] = (Seg){l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		push_up(u);
	}
}
void modify(int u, int l, int r, int c)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum = (tr[u].r - tr[u].l + 1) * c;
		tr[u].tag = c;
	}
	else
	{
		lazydown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		
		if(l <= mid) modify(u << 1, l, r, c);
		if(r > mid) modify(u << 1 | 1, l, r, c);
		push_up(u);
	}
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("data1.txt", "r", stdin);
	int T; cin >> T;
	while(T --)
	{
		memset(tr, 0, sizeof tr);
		cin >> n >> m;
		build(1, 1, n);
		
		while(m --)
		{
			int l, r, c;
			cin >> l >> r >> c;
			modify(1, l, r, c);
		}
		
		cout << tr[1].sum << endl;
	}
	
	return 0;
}
