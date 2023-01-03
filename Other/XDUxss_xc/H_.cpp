#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
struct Node {
	int l, r;
	int mn;
};

const int N = 2e5+10, INF = 1e9+7;

int n, m;
int w[N];
Node tr[N*10];

void pushup(int u) {
	tr[u].mn = min(tr[u<<1].mn, tr[u<<1|1].mn);
}
void build(int u, int l, int r) {
	if(l == r)  
		tr[u] = {l, r, w[r]};
	else {
		tr[u] = {l, r};
		int mid = l+r>>1;
		build(u<<1, l, mid), build(u<<1|1, mid+1, r);
		pushup(u);
	}
}
void modify(int u, int x, int c) {
	if(tr[u].l == x && tr[u].r == x) 
		tr[u].mn = c;
	else {
		int mid = tr[u].l+tr[u].r>>1;
		if(x <= mid) modify(u<<1, x, c);
		else modify(u<<1|1, x, c);
		pushup(u);
	}
}
int query(int u, int x, int c) {
	if(tr[u].mn > c || tr[u].r < x) return -1;
	if(tr[u].l == tr[u].r) return tr[u].r;
	int mid = tr[u].l+tr[u].r>>1;
	int res = -1;
	if(x <= mid && tr[u<<1].mn <= c) res = query(u<<1, x, c);
	if(!~res) res = query(u<<1|1, x, c);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;  // << setprecision(20); // double
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) w[i] = INF;
	build(1, 1, n);
	while(m --) {
		char op;
		int x, a;
		cin >> op >> x >> a;
		if(op == 'M') 
			modify(1, a, x);
		else 
			cout << query(1, a, x) << '\n';
	}
	return 0;
}