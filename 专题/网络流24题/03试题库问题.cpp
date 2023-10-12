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

const int N = 1e3, K = 20, NN = N+K+2, MM = 2*(N + N*K + K);
const int INF = 0x3f3f3f3f;

int n, k, S, T;

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
    mxflow.init();
    cin >> k >> n;
    S = 0, T = n+k+1;
    int tot = 0;
    for(int i = n+1; i <= n+k; i ++) {
        int x; cin >> x;
        mxflow.addFlow(i, T, x);
        tot += x;
    }
    for(int i = 1; i <= n; i ++) {
        mxflow.addFlow(S, i, 1);
        int p; cin >> p;
        while(p--) {
            int x; cin >> x;
            mxflow.addFlow(i, n+x, 1);
        }
    }
    auto &f = mxflow;
    int ans = f.dinic(S, T);
    if(ans != tot) {
        cout << "No Solution!\n";
        return;
    }
    for(int u = n+1; u <= n+k; u ++) {
        cout << u-n << ": ";
        for(int i = f.h[u]; ~i; i = f.ne[i]) {
            if(f.ver[i] <= n && f.e[i] == 1) {
                cout << f.ver[i] << ' ';
            }
        }
        cout << '\n';
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