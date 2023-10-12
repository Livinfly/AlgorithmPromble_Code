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

const int MO = 998244353;

void solve() {
    int n; cin >> n;
    vector<PII> p(n);
    for(auto &[x, y]: p) cin >> x;
    for(auto &[x, y]: p) cin >> y;
    sort(all(p));
    int m = 5000;
    vector<int> dp(m+1);
    dp[0] = 1;
    int ans = 0;
    for(auto [x, y]: p) {
        for(int j = 0; j <= x-y; j ++) {
            ans = (ans + dp[j]) % MO;
        }
        for(int j = m; j >= y; j --) {
            dp[j] = (dp[j] + dp[j-y]) % MO;
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