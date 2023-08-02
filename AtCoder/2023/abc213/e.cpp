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

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for(auto &s: g) cin >> s;
    PII freedxy[] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
    };
    PII costdxy[] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {0, 2}, {2, 0}, {0, -2}, {-2, 0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
    };
    int ans = -1;
    deque<PII> deq;
    deq.emplace_back(0, 0);
    vector<bool> vis(h*w);
    while(deq.size()) {
        auto [p, d] = deq.front();
        deq.pop_front();
        if(vis[p]) continue;
        vis[p] = true;
        if(p == h*w-1) {
            ans = d;
            break;
        }
        int x = p/w, y = p%w;
        // cerr << x << ' ' << y << ' ' << d << '\n';
        for(auto [dx, dy]: freedxy) {
            int a = x+dx, b = y+dy;
            if(a < 0 || a >= h || b < 0 || b >= w || g[a][b] == '#') continue;
            deq.emplace_front(a*w+b, d);
        }
        for(auto [dx, dy]: costdxy) {
            int a = x+dx, b = y+dy;
            if(a < 0 || a >= h || b < 0 || b >= w) continue;
            deq.emplace_back(a*w+b, d+1);
        }
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
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}