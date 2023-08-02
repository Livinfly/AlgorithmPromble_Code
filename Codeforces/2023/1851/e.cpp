#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n), deg(n);
    vector<vector<int>> e(n);
    for(auto &x: a) cin >> x;
    while(k --) {
        int x;
        cin >> x;
        a[--x] = 0;
    }
    for(int i = 0; i < n; i ++) {
        int m, x;
        cin >> m;
        while(m --) {
            cin >> x;
            e[--x].push_back(i);
            deg[i]++;
        }
    }
    vector<LL> d(n);
    auto bfs = [&]() {
        queue<int> q;
        for(int i = 0; i < n; i ++) {
            if(!deg[i]) {
                q.push(i);
                d[i] = a[i];
            }
        }
        while(q.size()) {
            auto u = q.front();
            q.pop();
            d[u] = min(d[u], a[u]);
            for(auto v: e[u]) {
                d[v] += d[u];
                if(--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
    };
    bfs();
    for(auto x: d) cout << x << ' ';
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}