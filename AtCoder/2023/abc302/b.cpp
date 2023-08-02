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
    vector<string> g(n);
    for(auto &x : g) cin >> x;

    vector<array<int, 2>> ans(5);

    for(int i = 0; i < n; i ++) {
    	for(int j = 0; j < m; j ++) {
    		for(int dx = -1; dx <= 1; dx ++) {
                for(int dy = -1; dy <= 1; dy ++) {
                    if(dx || dy) {
                        bool flag = true;
                        for(int k = 0; k < 5; k ++) {
                            int a = i + k*dx, b = j + k*dy;
                            if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] != "snuke"[k]) {
                                flag = false;
                                break;
                            }
                        }
                        if(flag) {
                            for(int k = 0; k < 5; k ++) {
                                int a = i + k*dx, b = j + k*dy;
                                cout << a+1 << ' ' << b+1 << '\n';
                            }
                            return;
                        }
                    }
                }
            }
    	}
    }
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