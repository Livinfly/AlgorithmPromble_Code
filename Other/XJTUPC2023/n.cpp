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
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<int> g(n);
    for(auto &x : g) cin >> x;
	LL res = c;
	for(int i = 0; i < n; i ++) {
		if(!i) {
			res += 1LL*g[i] * (a+b);
			res += a;
			continue;
		}
		res += 1LL*(g[i] - g[i-1] + m-1)%m * (a+b);
		res += a;
	}
	LL ans = res;
	bool ok = true;
	for(int i = 1; i < n; i ++) {
		if(g[i] != (g[i-1] + 1)%m) {
			ok = false;
			break;
		}
	}
	if(ok) {
		ans = 1LL*g[0] * (a+b) + n * a;
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
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}