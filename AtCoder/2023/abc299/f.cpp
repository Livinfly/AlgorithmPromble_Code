#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MO = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 26>> ne(n+1);
    ne[n].fill(n);
    for(int i = n-1; i >= 0; i --) {
        ne[i] = ne[i+1];
        ne[i][s[i]-'a'] = i;
    }
    int res = 0;
    for(int q1 = 1; q1 < n; q1 ++) {
        vector<vector<int>> dp(n);
        for(auto &v : dp)
            v.resize(n);
        if(ne[0][s[q1]-'a'] < q1) 
            dp[ne[0][s[q1]-'a']][q1] = 1;
        for(int x = 0; x < q1; x ++) {
            for(int y = q1; y < n; y ++) {
                if(ne[x+1][s[q1]-'a'] == q1) {
                    res = (res + dp[x][y]) % MO;
                }
                for(int c = 0; c < 26; c ++) {
                    int nx = ne[x+1][c], ny = ne[y+1][c];
                    if(nx < q1 && ny < n) {
                        dp[nx][ny] = (dp[nx][ny] + dp[x][y]) % MO;
                    }
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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