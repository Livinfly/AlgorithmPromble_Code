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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), f(2e5+1, -1), g(2e5+1, -1);
   	for(auto &x : a) cin >> x;
   	for(auto &x : b) cin >> x;
   	f[0] = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = 2e5; j >= a[i]; j --) {
			if(f[j-a[i]] != -1) {
				f[j] = max(f[j], f[j-a[i]] + b[i]);
			}
		}
	}
	for(int S = 1; S <= 2e5; S ++) {
		for(int T = S; T; T = (T-1) & S) {
			if(T < k) continue;
			g[S] = max(g[S], f[T]);
		}
	}
	int ans = -1;
	for(int i = 1; i <= 2e5; i ++) {
		if(g[i] != -1 && (i^((1<<18)-1)) <= 2e5 && g[i^((1<<18)-1)] != -1) {
			ans = max(ans, g[i] + g[i^((1<<18)-1)]);
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
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}