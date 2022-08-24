#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5010;

int n, m, cnt;
int ones[N + 2000];
char str[N];
struct Node
{
	int l, r;
	int sum;
	int cnt;
	int tag;
} tr[N << 2];

void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void lazydown(int u)
{
	if(tr[u].tag)
	{
		Node &l = tr[u << 1], &r = tr[u << 1 | 1];
		l.sum = l.cnt - l.sum, l.tag ^= 1;
		r.sum = r.cnt - r.sum, r.tag ^= 1;
		tr[u].tag = 0;
	}
}
void build(int u, int l, int r)
{
	if(l == r) tr[u] = (Node) {l, r, str[r] - 48, 1, 0};
	else
	{
		tr[u] = (Node) {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
		pushup(u);
	}
}
void modify(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r) 
	{
		tr[u].sum = tr[u].cnt - tr[u].sum;
		tr[u].tag ^= 1;
	}
	else
	{
		lazydown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(u << 1, l, r);
		if(r > mid) modify(u << 1 | 1, l, r);
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
		if(l <= mid) res += query(u << 1, l, r);
		if(r > mid) res += query(u << 1 | 1, l, r);
		return res;
	}
}
int qpm(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d%d%s", &n, &m, str + 1);
	
	build(1, 1, n);
	
	int pos = n;
	while(m --)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		modify(1, l, r);
		int tmp = 0;
		for(int i = l, t = 1; i <= r; i ++, t *= 2) tmp += (str[i] - 48) * t;
		pos = pos + qpm(2, r - l + 1);
		ones[cnt ++] = pos - tmp;
	}
	
	printf("%d\n", tr[1].sum);
	for(int i = 1; i <= n; i ++)
		if(query(1, i, i) == 1)
			printf("%d ", i);
	
	for(int i = 0; i < cnt; i ++)
		printf("%d ", ones[i]);
	
	puts("");	
	
	return 0;
}
