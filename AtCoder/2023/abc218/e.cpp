// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

struct DSU {
    vector<int> fa, siz;

    void init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        for(int i = 0; i <= n; i ++) 
            fa[i] = i, siz[i] = 1;
    }
    int leader(int x, bool compress = true) {
        if(x == fa[x]) return x;
        int root = leader(fa[x]);
        return compress ? fa[x] = root : root;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    bool merge(int x, int y, bool strict = true) {
        x = leader(x), y = leader(y);
        if(x == y) return false;
        if(!strict && siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return siz[leader(x)];
    }
}dsu;

void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(all(edges));
    dsu.init(n);
    LL ans = 0;
    for(auto [w, x, y]: edges) {
        int fx = dsu.leader(x), fy = dsu.leader(y);
        if(fx != fy) dsu.merge(x, y);
        else if(w > 0) ans += w;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}