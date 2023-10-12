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
    const int MO = 1e9+7;
    string s; cin >> s;
    int n = s.size();
    vector<int> dp(n+2);
    dp[0] = 1, dp[1] = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = i-1; j >= -1; j --) {
            dp[i+2] = (dp[i+2] + dp[j+2 - 1]) % MO;
            if(j == -1 || s[i] == s[j]) break;
        }
    }
    LL ans = 0;
    for(int i = 2; i < n+2; i ++) ans += dp[i];
    cout << ans % MO << '\n';
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