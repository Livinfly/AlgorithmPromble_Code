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

const int N = 1025, MO = 998244353;

int dp[N][N][10];

void solve() {
    int n; string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int j = s[i-1]-'A';
        for(int st = 0; st < (1<<10); st ++) {
            for(int x = 0; x < 10; x ++) {
                dp[i][st][x] = dp[i-1][st][x];
                if(x == j) {
                    dp[i][st][x] += dp[i-1][st][x];
                    dp[i][st][x] %= MO;
                }
            }
        }
        for(int st = 0; st < (1<<10); st ++) {
            if(st>>j & 1) continue;
            for(int x = 0; x < 10; x ++) {
                dp[i][st | (1<<j)][j] += dp[i-1][st][x];
                dp[i][st | (1<<j)][j] %= MO;
            }
        }
        dp[i][(1<<j)][j]++;
        dp[i][(1<<j)][j] %= MO;
    }
    for(int st = 0; st < (1<<10); st ++) {
        for(int j = 0; j < 10; j ++) {
            ans += dp[n][st][j];
            ans %= MO;
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