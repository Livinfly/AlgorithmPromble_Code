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

map<char, int> mpt = {
    {'L', 0},
    {'R', 1},
    {'D', 2},
    {'U', 3},
};
array<int, 2> dxy[] = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0},
};
int n, m, sx, sy, ex, ey, ans, res;
string dir;
bool flag;
bool vis[50010][16];

void dfs(int x, int y, string dir) {
    // cerr << x << ' ' << y << ' ' << dir << '\n';
    if(x == ex && y == ey) {
        flag = true;
        return;
    }
    int d = 0, a = x, b = y;
    for(auto x: dir) {
        int t = mpt[x];
        d = d*4 + t;
        auto [dx, dy] = dxy[t];
        a += dx, b += dy;
    }
    int p = x*m+y;
    if(vis[p][d]) return;
    vis[p][d] = true;
    bool ok = false;
    if(a == -1 || a == n) {
        if(a == -1) a = 1;
        else a = n-2;
        ok = true;
        if(dir[0] == 'U') dir[0] = 'D';
        else dir[0] = 'U';
    }
    if(b == -1 || b == m)  {
        if(b == -1) b = 1;
        else b = m-2;
        ok = true;
        if(dir[1] == 'L') dir[1] = 'R';
        else dir[1] = 'L';
    }
    if(ok) ans++;
    dfs(a, b, dir);
    vis[p][d] = false;
}
void solve() {
    ans = 0, flag = false;
    cin >> n >> m >> sx >> sy >> ex >> ey >> dir;
    sx--, sy--, ex--, ey--;
    dfs(sx, sy, dir);
    if(!flag) ans = -1;
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}