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

const int N = 100, M = N*N, NN = N*2+2, MM = 2*(M + N*2);
const LL INF = 0x3f3f3f3f3f3f3f3f;

template<class U>
struct MinCostMaxFlow { // By Dinic
    int S, T;
    int idx, h[NN], ne[MM], ver[MM];
    U mxflow, mncost, e[MM], w[MM], d[NN]; // d[]可以int，但注意INF的值是否爆int
    U cur[NN];
    bool vis[NN];
    void init() {
        idx = 0, memset(h, -1, sizeof h);
    }
    void add(int a, int b, U c, U d) {
        ver[idx] = b, e[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++;
    }
    void addFlow(int a, int b, U d, U c1, U c2 = 0) {
        add(a, b, c1, d), add(b, a, c2, -d);
    }
    bool spfa() {
        queue<int> q;
        q.push(S);
        memset(d, 0x3f, sizeof d);
        d[S] = 0, vis[S] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            cur[u] = h[u]; vis[u] = false;
            for(int i = h[u]; ~i; i = ne[i]) {
                int v = ver[i];
                if(d[v] > d[u] + w[i] && e[i] > 0) {
                    d[v] = d[u]+w[i];
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return d[T] < INF;
    }
    U update(int u, U limit) {
        if(u == T) return limit;
        vis[u] = true;
        U flow = 0;
        for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
            cur[u] = i;
            int v = ver[i];
            if(!vis[v] && d[v] == d[u]+w[i] && e[i] > 0) {
                U t = update(v, min(e[i], limit-flow));
                if(!t) d[v] = INF; // INF是否爆d[]，mark
                mncost += t * w[i];
                flow += t;
                e[i] -= t;
                e[i^1] += t;
            }
        }
        vis[u] = false;
        return flow;
    }
    pair<U, U> dinic(int s, int t) {
        S = s, T = t;
        U flow;
        mxflow = mncost = 0; 
        while(spfa()) 
            while(flow = update(S, INF))
                mxflow += flow;
        return {mxflow, mncost};
    }
};
MinCostMaxFlow<LL> mcmf; // init

void solve() {
    int n; cin >> n;
    int S = 0, T = 2*n+1;
    vector<vector<int>> w(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++) 
            cin >> w[i][j];
    mcmf.init();
    for(int i = 1; i <= n; i ++) mcmf.addFlow(S, i, 0, 1);
    for(int i = 1; i <= n; i ++) mcmf.addFlow(i+n, T, 0, 1);
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++) 
            mcmf.addFlow(i, j+n, w[i][j], 1);
    auto [_, ans1] = mcmf.dinic(S, T);
    cout << ans1 << '\n';
    mcmf.init();
    for(int i = 1; i <= n; i ++) mcmf.addFlow(S, i, 0, 1);
    for(int i = 1; i <= n; i ++) mcmf.addFlow(i+n, T, 0, 1);
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++) 
            mcmf.addFlow(i, j+n, -w[i][j], 1);
    auto [__, ans2] = mcmf.dinic(S, T);
    cout << -ans2 << '\n';
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