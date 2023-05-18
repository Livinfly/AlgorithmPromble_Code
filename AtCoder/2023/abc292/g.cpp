#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

 
  int N = 45, MO = 998244353;

int f[N][N][N][11];

void solve() {
	memset(f, -1, sizeof f);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &v : a) cin >> v;
    function<int(int, int, int, int)> dfs = [&](int l, int r, int k, int c) {
    	auto &ff = f[l][r][k][c];
    	if(~ff) return ff;
    	if(k == m) return ff = (l == r);
    	if(l > r) return ff = 1;
    	if(c == 10) return ff = 0;
    	ff = dfs(l, r, k, c+1);
    	for(int i = l; i <= r; i ++) {
    		if(a[i][k] != '?' && a[i][k] != '0'+c) {
    			break;
    		}
    		ff = (1LL*ff + 1LL*dfs(l, i, k+1, 0)*dfs(i+1, r, k, c+1) % MO) % MO;
    	}
    	return ff;
    };
    cout << dfs(0, n-1, 0, 0) << '\n';
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