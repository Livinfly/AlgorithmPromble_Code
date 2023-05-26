#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1), c(n+1);
	vector<bool> vis(n+1);
    vector<vector<LL>> dp(n+2, vector<LL>(n+2, INF));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 0; i < m; i ++) {
    	int x;
    	cin >> x;
    	vis[x] = true;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
		int cost = 1e9;
		for(int j = 0; j <= i; j ++) {
			cost = min(cost, c[i-j]);
			dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] + cost + a[i]);
			if(!vis[i]) {
				dp[i][j] = min(dp[i][j], dp[i-1][j]);
			}
		}
    }
    cout << *min_element(all(dp[n])) << '\n';
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