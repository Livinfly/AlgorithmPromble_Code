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
    int n, t;
    cin >> n >> t;
    vector<int> c(n), r(n);
    
    for(auto &x : c) cin >> x;
    for(auto &x : r) cin >> x;

    int p = -1;
    bool ok = false;
	for(int i = 0; i < n; i ++) {
		if(c[i] == t) {
			ok = true;
			if(p == -1 || r[p] < r[i]) p = i;
			// cout << i << ' ' << r[p] << ' ' << r[i] << '\n';
		}
	}
	if(!ok) {
		p = 0;
		for(int i = 0; i < n; i ++) {
			if(c[i] == c[0]) {
				if(r[p] < r[i]) p = i;
			}
		}
	}
	cout << p+1 << '\n';
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