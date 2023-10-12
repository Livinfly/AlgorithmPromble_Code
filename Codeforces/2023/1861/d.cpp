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

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    const int INF = 1e9;
    vector<array<int, 2>> dp(n+1, {INF, INF});
    for(int i = 1; i <= n; i ++) cin >> a[i];
    dp[1][1] = 0, dp[1][0] = 1;
    for(int i = 2; i <= n; i ++) {
        if(a[i-1] >= a[i]) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][1] + 1);
            dp[i][0] = dp[i-1][0] + (a[i-1] == a[i]);
        }
        else {
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = dp[i-1][0] + 1;
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}