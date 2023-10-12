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

const int N = 410, INF = 0x3f3f3f3f;

vector<int> e[N];
int n, m, d[N], pre[N];
bool vis[N][N];

int bfs(int bx, int by) {
    memset(d, 0x3f, sizeof d);
    memset(pre, 0, sizeof pre);
    queue<int> q;
    q.push(1), d[1] = 0, pre[1] = -1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == n) break;
        for(auto v: e[u]) {
            if(u == bx && v == by) continue;
            if(d[v] > d[u]+1) {
                d[v] = d[u]+1;
                pre[v] = u;
                q.push(v);
            }
        }
    }
    return d[n] == INF ? -1 : d[n];
}
void solve() {
    cin >> n >> m;
    vector<PII> edges(m);
    for(int i = 0; i < m; i ++) {
        auto &[x, y] = edges[i];
        cin >> x >> y;
        e[x].pb(y);
    }
    int ans = bfs(-1, -1);
    if(d[n] != INF) {
        int t = n;
        while(pre[t] != -1) {
            vis[pre[t]][t] = true;
            t = pre[t];
        }
    }
    for(auto [x, y]: edges) {
        if(!vis[x][y]) cout << ans << '\n';
        else cout << bfs(x, y) << '\n';
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