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

const int N = 1e4+10, NN = 200*N, MM = NN, M = 1e6+10;
const int INF = 0x3f3f3f3f;

int Nid, nid[N][20];
int n, m, S, T;

template<class U>
struct MaxFlow {
    int S, T;
    int idx, h[NN], ne[MM], ver[MM];
    U e[MM];
    int d[NN], cur[NN];
    void init(int s, int t) {
        idx = 0, memset(h, -1, sizeof h);
        S = s, T = t;
    }
    void add(int a, int b, U c) {
        ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    }
    void addFlow(int a, int b, U c1, U c2) {
        add(a, b, c1), add(b, a, c2);
    }
    bool bfs() {
        queue<int> q;
        memset(d, -1, sizeof d);
        q.push(S);
        d[S] = 0, cur[S] = h[S];
        while(q.size()) {
            int t = q.front(); q.pop();
            for(int i = h[t]; ~i; i = ne[i]) {
                int v = ver[i];
                if(d[v] == -1 && e[i] > 0) {
                    d[v] = d[t]+1;
                    cur[v] = h[v];
                    if(v == T) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    U update(int u, U limit) {
        if(u == T) return limit;
        U flow = 0;
        for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
            cur[u] = i;
            int v = ver[i];
            if(d[v] == d[u]+1 && e[i] > 0) {
                U t = update(v, min(e[i], limit-flow));
                if(!t) d[v] = -1;
                flow += t;
                e[i] -= t;
                e[i^1] += t;
            }
        }
        return flow;
    }
    U dinic() {
        U ret = 0, flow;
        while(bfs()) 
            while(flow = update(S, INF))
                ret += flow;
        return ret;
    }
};
MaxFlow<int> mxflow;
struct MultiplyLCA {
    static const int _K = 20;
    vector<vector<array<int, 2>>> e;
    vector<int> dep;
    vector<array<int, _K>> fa;
    void init(int n) {
        dep.assign(n+1, 0);
        e.assign(n+1, {});
        fa.assign(n+1, {});
    }
    void add(int a, int b, int c) {
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    void build(int root = 1) {
        bfs(root);
    }
    void bfs(int root) {
        queue<int> q;
        dep[root] = 1, q.push(root);
        while(q.size()) {
            int u = q.front();
            q.pop();
            for(auto [v, c] : e[u]) {
                if(dep[v]) continue;
                dep[v] = dep[u] + 1;
                fa[v][0] = u;
                nid[v][0] = ++Nid;
                mxflow.addFlow(nid[v][0], T, c, 0);
                for(int j = 1; j < _K; j ++) {
                    fa[v][j] = fa[fa[v][j - 1]][j - 1];
                    nid[v][j] = ++Nid;
                    mxflow.addFlow(nid[v][j], nid[v][j-1], INF, 0);
                    mxflow.addFlow(nid[v][j], nid[fa[v][j-1]][j-1], INF, 0);
                }
                q.push(v);
            }
        }
    }
    int LCA(int x, int y) {
        if(dep[x] < dep[y]) swap(x, y);
        for(int k = _K-1; k >= 0; k --)
            if(dep[fa[x][k]] >= dep[y])
                x = fa[x][k];
        if(x == y) return x;
        for(int k = _K-1; k >= 0; k --) 
            if(fa[x][k] != fa[y][k])
                x = fa[x][k], y = fa[y][k];
        return fa[x][0];
    }
    void addx2lr(int from, int l, int r, int c) {
        if(dep[l] < dep[r]) swap(l, r);
        for(int k = _K-1; k >= 0; k --) {
            if(dep[fa[l][k]] >= dep[r]) {
                mxflow.addFlow(from, nid[l][k], c, 0);
                l = fa[l][k];
            }
        }
        if(l == r) return;
        for(int k = _K-1; k >= 0; k --) {
            if(fa[l][k] != fa[r][k]) {
                mxflow.addFlow(from, nid[l][k], c, 0);
                mxflow.addFlow(from, nid[r][k], c, 0);
                l = fa[l][k], r = fa[r][k];
            }
        }
        mxflow.addFlow(from, nid[l][0], c, 0);
        mxflow.addFlow(from, nid[r][0], c, 0);
    }
}mlca;
void solve() {
    cin >> n >> m;
    S = NN-2, T = NN-1, Nid = 0;
    mxflow.init(S, T);
    vector<array<int, 3>> rec(n);
    mlca.init(n);
    for(int i = 1; i < n; i ++) {
        auto &[u, v, c] = rec[i];
        cin >> u >> v >> c;
        mlca.add(u, v, c);
    }
    mlca.build();
    int ans = 0;
    while(m--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        x -= y;
        if(x > 0) {
            Nid++;
            ans += x;
            mxflow.addFlow(S, Nid, x, 0);
            mlca.addx2lr(Nid, a, b, INF);
        }
    }
    // cerr << dinic() << '\n';
    ans -= mxflow.dinic();
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
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}