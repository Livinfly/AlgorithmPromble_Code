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
	int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    for(auto &s : a) cin >> s;
	for(auto &s : b) cin >> s;

	auto st = [&](int x, int y) {
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++) 
				if(a[(i+x)%n][(j+y)%m] != b[i][j])
					return false;
		return true;
	};

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			if(st(i, j)) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";
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