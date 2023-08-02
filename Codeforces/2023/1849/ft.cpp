#pragma GCC optimize(2)

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
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        auto &[x, id] = a[i];
        cin >> x;
        id = i;
    }
    sort(all(a));
    vector<int> col(n);
    vector<array<int, 3>> edges;
    for(int i = 0; i < n; i ++) {
        for(int j = i+1; j < n && j <= i+3; j ++) {
            edges.push_back({a[i][0] ^ a[j][0], a[i][1], a[j][1]});
        }
    }
    sort(all(edges));
    dsu.init(n);
    vector<vector<int>> e(n);
    for(auto [_, x, y]: edges) {
        if(dsu.merge(x, y, false)) {
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    function<void(int, int)> dfs = [&](int u, int p) {
        for(auto v: e[u]) {
            if(v == p) continue;
            col[v] = col[u] ^ 1;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    for(int i = 0; i < n; i ++) {
        cout << col[i];
    }
    cout << '\n';
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
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}