#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<PDD> a(n), b(m);
    for(auto &[x, y] : a)
    	cin >> x >> y;
    for(auto &[x, y] : b)
    	cin >> x >> y;
    double l = 0, r = 1;
    for(int z = 0; z < 100; z ++) {
    	double mid = (l+r)/2;
    	double t = mid / (1-mid);
    	vector<double> v(m);
    	for(int i = 0; i < m; i ++) {
    		auto &x = v[i];
    		auto [c, d] = b[i];
    		x = c - d*t;
    	}
    	sort(all(v));
    	LL num = 0;
    	for(auto [x, y] : a) {
    		double w = x - y*t;
    		num += m - (lower_bound(all(v), -w) - v.begin());
    	}
    	(num < k ? r : l) = mid;
    }
    cout << r * 100 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12); // double
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