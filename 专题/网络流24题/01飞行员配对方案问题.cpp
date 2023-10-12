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

const int N = 100, M = N*(N-1)/2, NN = N+2, MM = 2*(M + N), INF = 0x3f3f3f3f;

int S, T;

template<class U>
struct MaxFlow {
    int S, T;
    int idx, h[NN], ne[MM], ver[MM];
    U mxflow, e[MM];
    int d[NN], cur[NN];
    void init() {
        idx = 0, memset(h, -1, sizeof h);
    }
    void add(int a, int b, U c) {
        ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    }
    void addFlow(int a, int b, U c1, U c2 = 0) {
        add(a, b, c1), add(b, a, c2);
    }
    bool bfs() {
        queue<int> q; q.push(S);
        memset(d, -1, sizeof d);
        d[S] = 0, cur[S] = h[S];
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = h[u]; ~i; i = ne[i]) {
                int v = ver[i];
                if(d[v] == -1 && e[i] > 0) {
                    d[v] = d[u]+1;
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
    U dinic(int s, int t) {
        S = s, T = t;
        U flow;
        mxflow = 0;
        while(bfs()) 
            while(flow = update(S, INF))
                mxflow += flow;
        return mxflow;
    }
};
MaxFlow<int> mxflow;


void solve() {
    int n1, n2, m = 0; cin >> n1 >> n2;
    S = 0, T = n2+1;
    mxflow.init();
    for(int i = 1; i <= n2; i ++) {
        if(i <= n1) mxflow.addFlow(S, i, 1);
        else mxflow.addFlow(i, T, 1);
    }
    int x, y;
    while(cin >> x >> y && (x != -1 || y != -1)) {
        mxflow.addFlow(x, y, 1);
        m++;
    }
    int ans = mxflow.dinic(S, T);
    cout << ans << '\n';
    auto &f = mxflow;
    for(int i = 1; i < f.idx; i += 2) {
        if(f.e[i] == 1 && f.ver[i] >= 1 && f.ver[i] <= n1 && f.ver[i^1] > n1 && f.ver[i^1] <= n2) {
            cout << f.ver[i] << ' ' << f.ver[i^1] << '\n';
        }
    }
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