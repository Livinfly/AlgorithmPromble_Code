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
    LL n, m, d;
    cin >> n >> m >> d;
    vector<LL> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(all(b));
	LL ans = -1;
	for(int i = 0; i < n; i ++) {
		// int l = 0, r = m-1;
		// while(l < r) {
		// 	int mid = l + r + 1 >> 1;
		// 	if(b[mid] <= a[i]+d) l = mid;
		// 	else r = mid-1;
		// }
		// if(b[r] <= a[i]+d && b[r] >= a[i]-d) {
		// 	ans = max(ans, b[r]+a[i]);
		// }
        auto it = upper_bound(all(b), a[i]+d);
        if(it != b.begin()) {
            LL t = *(it - 1);
            if(t >= a[i]-d) {
                ans = max(ans, a[i]+t);
            }
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