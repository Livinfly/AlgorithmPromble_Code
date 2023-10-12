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
    string s; cin >> s;
    int n = s.size(), c0 = count(all(s), '0'), c1 = n-c0;
    // c01==c10, c01 + c11
    int m = (n*(n-1)/2 - c0*(c0-1)/2 - c1*(c1-1)/2)/2 + c1*(c1-1)/2;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> dp(c1+1, vector<int>(m+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = c1-1; j >= 0; j --) {
            for(int k = 0; k+i <= m; k ++) {
                dp[j+1][k+i] = min(dp[j+1][k+i], dp[j][k] + (s[i]=='0'));
                // cerr << dp[j+1][k+i] << '\n';
            }
        }
    }
    cout << dp[c1][m] << '\n';
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