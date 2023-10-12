// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
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
    int n; cin >> n;
    vector<tuple<int, int, int>> edges(n-1);
    for(auto &[w, u, v]: edges) {
        cin >> u >> v >> w;
    }
    sort(all(edges));
    dsu.init(n);
    LL ans = 0;
    for(auto [w, x, y]: edges) {
        // tree, absolutely diff
        ans += 1LL* dsu.size(x) * dsu.size(y) * w;
        dsu.merge(x, y);
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