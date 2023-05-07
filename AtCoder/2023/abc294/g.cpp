#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

struct Rec {
	int a, b, c;
};
vector<PII> e[N];
vector<Rec> ee;
int d[N], fa[N][20], siz[N], dfn[N], tms;
LL dist[N];

template <typename T>
struct FenwickTree {
    int n;
    vector<T> a;
    void Init(int n) {
        this->n = n;
        a.assign(n+1, 0);
    }
    int Lowbit(int x) {
        return x & -x;
    }
    void Add(int x, T v) {
        for( ; x <= n; x += Lowbit(x))
            a[x] += v;
    }
    T Sum(int x) {
        auto ans = T();
        for( ; x; x -= Lowbit(x))
            ans += a[x];
        return ans;
    }
    T RangeSum(int l, int r) {
        return Sum(r) - Sum(l-1);
    }
};
FenwickTree<LL> fen; // int / LL
void dfs1(int u) {
    dfn[u] = ++ tms;
    siz[u] = 1;
	for(auto [v, c] : e[u]) {
		if(!d[v]) {
			d[v] = d[u] + 1;
			dist[v] = dist[u] + c;
			fa[v][0] = u;
			for(int k = 1; k < 20; k ++)
				fa[v][k] = fa[fa[v][k-1]][k-1];
			dfs1(v);
            siz[u] += siz[v];
		}
	}
}
void Modify(int u, LL c) {
    fen.Add(dfn[u], c);
    fen.Add(dfn[u]+siz[u], -c);
}
int LCA(int x, int y) {
    if(d[x] < d[y]) swap(x, y);
    for(int k = 19; k >= 0; k --) 
        if(d[fa[x][k]] >= d[y])
            x = fa[x][k];
    if(x == y) return x;
    for(int k = 19; k >= 0; k --) 
        if(fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}
void solve() {
    int n;
    cin >> n;
    ee.resize(n);
    for(int i = 1; i < n; i ++) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	e[a].emplace_back(b, c);
    	e[b].emplace_back(a, c);
    	ee[i] = {a, b, c};
    }
    for(int k = 0; k < 20; k ++)
    	fa[1][k] = 1;
    d[1] = 1, dist[1] = 0;
    dfs1(1);
    fen.Init(n);
    int Q;
    cin >> Q;
    while(Q --) {
    	int op;
    	cin >> op;
    	if(op == 1) {
    		int i, w;
    		cin >> i >> w;
    		auto &[a, b, c] = ee[i];
    		if(d[b] > d[a]) swap(a, b);
			Modify(a, w-c);
            c = w;
    	}
    	else {
    		int u, v;
    		cin >> u >> v;
            // cerr << "-------\n";
            // cerr << u << ' ' << v << ' ' << LCA(u, v) << '\n'; 
            // cerr << dist[u] << ' ' << dist[v] << ' ' << dist[LCA(u, v)] << '\n';
            // cerr << "-------\n";
            int lca = LCA(u, v);
    		cout << dist[u]+fen.Sum(dfn[u]) + dist[v]+fen.Sum(dfn[v]) - 2*(dist[lca]+fen.Sum(dfn[lca])) << '\n';
    	}
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}