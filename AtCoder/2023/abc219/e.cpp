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

int dxy[4][2] = {
    {0, -1}, 
    {0, 1},
    {1, 0}, 
    {-1, 0},
};
bool g[4][4], vis[4][4], out;

void dfs1(int x, int y) {
    vis[x][y] = true;
    for(auto [dx, dy]: dxy) {
        int a = x+dx, b = y+dy;
        if(a < 0 || a >= 4 || b < 0 || b >= 4) continue;
        if(!g[a][b] || vis[a][b]) continue;
        dfs1(a, b);
    }
}
void dfs2(int x, int y) {
    vis[x][y] = true;
    if(x == 0 || x == 3 || y == 0 || y == 3) out = true;
    for(auto [dx, dy]: dxy) {
        int a = x+dx, b = y+dy;
        if(a < 0 || a >= 4 || b < 0 || b >= 4) continue;
        if(g[a][b] || vis[a][b]) continue;
        dfs2(a, b);
    }
}
bool check(int S) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            g[i][j] = S>>(15-(i*4+j)) & 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(g[i][j] && !vis[i][j]) {
                dfs1(i, j);
                cnt++;
            }
        }
    }
    if(cnt > 1) return false;
    bool ok = true;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!g[i][j] && !vis[i][j]) {
                out = false;
                dfs2(i, j);
                if(!out) ok = false;
            }
        }
    }
    return ok;
}
void solve() {
    int p = 0;
    for(int i = 0; i < 16; i++) {
        int x; cin >> x;
        p = p<<1 | x;
    }
    const int tot = 1<<16;

    int ans = 0;
    for(int i = 0; i < tot; i++) {
        if((i&p) == p) {
            memset(vis, 0, sizeof vis);
            ans += check(i);
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}