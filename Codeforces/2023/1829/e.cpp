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

const int N = 1010;

array<int, 2> dxy[] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};
int n, m, ans;
int g[N][N];

int dfs(int x, int y) {
    int sum = g[x][y];
    g[x][y] = 0;
    for(auto [dx, dy]: dxy) {
        int a = x+dx, b = y+dy;
        if(a < 0 || a >= n || b < 0 || b >= m || !g[a][b]) continue;
        sum += dfs(a, b);
    }
    return sum;
}
void solve() {
    // cerr << "------------\n";
    ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(g[i][j]) {
                ans = max(ans, dfs(i, j));
                // cerr << i << ' ' << j << ' ' << dfs(i, j) << '\n';
            }
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}