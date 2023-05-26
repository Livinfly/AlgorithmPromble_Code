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
    int n;
    cin >> n;
    vector<int> pw3(n+1);
    pw3[0] = 1;
    for(int i = 1; i <= n; i ++) {
    	pw3[i] = pw3[i-1]*3;
    }
    const int N = pw3[n];
    vector<int> a(N);
    for(auto &x : a) cin >> x;
	for(int i = 0; i < n; i ++) {
		int p = pw3[i];
		for(int j = 0; j < N; j ++) {
			if((j/p) % 3 == 0) { // no repeat
				int p0 = j, p1 = p0+p, p2 = p1+p;
				int v0 = a[p0], v1 = a[p1], v2 = a[p2];
				a[p0] = v1 - v2;
				a[p1] = v0 - v1 + v2;
				a[p2] = -v0 + v1;
			}
		}
	}
	for(auto x : a) {
		cout << x << ' ';
	}
	cout << '\n';
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