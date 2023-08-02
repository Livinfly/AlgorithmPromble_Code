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
    const int INF = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto &v : a) 
        for(auto &x : v) 
            cin >> x;

    array<array<int, 2>, 2> dp{INF, INF, INF, INF};
    dp[0][0] = 0, dp[0][1] = 1;
    for(int i = 1; i <= n; i ++) {
        array<array<int, 2>, 2> ndp{INF, INF, INF, INF};
        for(int x = 0; x < 2; x ++) {
            for(int y = 0; y < 2; y ++) {
                for(int z = 0; z < 2; z ++) {
                    bool good = true;
                    for(int j = 0; j < m; j ++) { // make i-1 vaild
                        bool ok = false;
                        if(i > 1 && (a[i-2][j] ^ x) == (a[i-1][j] ^ y)) ok = true;
                        if(j > 0 && a[i-1][j-1] == a[i-1][j]) ok = true;
                        if(j < m-1 && a[i-1][j] == a[i-1][j+1]) ok = true;
                        if(i < n && (a[i][j] ^ z) == (a[i-1][j] ^ y)) ok = true;
                        if(!ok) good = false;
                    }
                    if(good) {
                        ndp[y][z] = min(ndp[y][z], dp[x][y] + z);
                    }
                }
            }
        }
        dp = ndp;
    }
    int ans = INF;
    for(auto x : dp) {
        for(auto y : x) {
            ans = min(ans, y);
        }
    }
    if(ans == INF) ans = -1;
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