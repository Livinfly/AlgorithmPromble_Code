#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct Rec {
    int a, b, c;
};
vector<Rec> ee;

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
struct HeavyLightDecompotion {
    int n, tms;
    vector<int> siz, top, dep, fa, dfni, dfno, rnk;
    vector<vector<int>> e;

    void Init(int n) {
        this->n = n;
        siz.resize(n+1);
        top.resize(n+1);
        dep.resize(n+1);
        fa.resize(n+1);
        dfni.resize(n+1);
        dfno.resize(n+1);
        rnk.resize(n+1);
        tms = 0;
        e.assign(n+1, {});
    }
    void AddEdge(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    void Build(int root = 1) {
        top[root] = root;
        dep[root] = 1;
        fa[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (fa[u] != -1) {
            e[u].erase(find(all(e[u]), fa[u]));
        }
        siz[u] = 1;
        for (auto &v : e[u]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[e[u][0]]) {
                swap(v, e[u][0]);
            }
        }
    }
    void dfs2(int u) {
        dfni[u] = ++ tms;
        rnk[dfni[u]] = u;
        for (auto v : e[u]) {
            top[v] = (v == e[u][0]) ? top[u] : v;
            dfs2(v);
        }
        dfno[u] = tms+1;
    }
    int LCA(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = fa[top[u]];
            }
            else {
                v = fa[top[v]];
            }
        }
        return (dep[u] < dep[v]) ? u : v;
    }
    int GetDist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
    }
    int Jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        int d = dep[u] - k;
        while (dep[top[u]] > d) {
            u = fa[top[u]];
        }
        return rnk[dfni[u] - dep[u] + d];
    }
}hld;
void Modify(int u, LL c) {
    fen.Add(hld.dfni[u], c);
    fen.Add(hld.dfno[u], -c);
}
void solve() {
    int n;
    cin >> n;
    ee.resize(n);
    hld.Init(n);
    for(int i = 1; i < n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        hld.AddEdge(a, b);
        ee[i] = {a, b, c};
    }
    hld.Build();
    fen.Init(n);
    for(int i = 1; i < n; i ++) {
        auto &[a, b, c] = ee[i];
        if(hld.fa[a] == b) {
            swap(a, b);
        }
        fen.Add(hld.dfni[b], c);
        fen.Add(hld.dfno[b], -c);
    }
    int Q;
    cin >> Q;
    while(Q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, w;
            cin >> i >> w;
            auto &[a, b, c] = ee[i];
            Modify(b, w-c);
            c = w;
        }
        else {
            int u, v;
            cin >> u >> v;
            int lca = hld.LCA(u, v);
            // cerr << "-------\n";
            // cerr << u << ' ' << v << ' ' << lca << '\n'; 
            // cerr << fen.Sum(hld.dfni[u]) << ' ' << fen.Sum(hld.dfni[v]) << ' ' << fen.Sum(hld.dfni[lca]) << '\n';
            // cerr << "-------\n";
            cout << fen.Sum(hld.dfni[u]) + fen.Sum(hld.dfni[v]) - 2*fen.Sum(hld.dfni[lca]) << '\n';
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