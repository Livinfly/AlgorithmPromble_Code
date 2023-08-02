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
    vector<int> a(n);
    for(auto &x : a) {
    	cin >> x;
    	x --;
    }
    vector<int> b = a;
	sort(all(b));
	int cnt[4][4] = {};
	for(int i = 0; i < n; i ++) {
		cnt[a[i]][b[i]] ++;
	}
	int ans = 0;
	for(int i = 0; i < 4; i ++) {
		for(int j = i+1; j < 4; j ++) {
			int t = min(cnt[i][j], cnt[j][i]);
			cnt[i][j] -= t, cnt[j][i] -= t;
			ans += t;
		}
	}
	for(int i = 0; i < 4; i ++) {
		for(int j = 0; j < 4; j ++) {
			for(int k = 0; k < 4; k ++) {
				if(i != j && j != k && j != i) {
					int t = min({cnt[i][j], cnt[j][k], cnt[k][i]});
					cnt[i][j] -= t, cnt[j][k] -= t, cnt[k][i] -= t;
					ans += t * 2;
				}
			}
		}
	}
	for(int i = 0; i < 4; i ++) {
		for(int j = 0; j < 4; j ++) {
			for(int k = 0; k < 4; k ++) {
				for(int u = 0; u < 4; u ++) {
					if(i != j && j != k && j != u && u != i) {
						int t = min({cnt[i][j], cnt[j][k], cnt[k][u], cnt[u][i]});
						cnt[i][j] -= t, cnt[j][k] -= t, cnt[k][u] -= t, cnt[u][i] -= t;
						ans += t * 3;
					}
				}
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