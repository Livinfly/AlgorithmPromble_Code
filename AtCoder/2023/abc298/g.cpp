#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int h, w, T;
LL a[6][6], s[6][6][6][6];
LL dp[6][6][6][6][36];
vector<LL> val;

LL dfs(LL lo, int x1, int x2, int y1, int y2, int k) {
	if((x2-x1+1)*(y2-y1+1)-1 < k) {
		return 1e18;
	}
	auto &f = dp[x1][x2][y1][y2];
	if(f[k] != -1) {
		return f[k];
	}
	f[k] = 1e18; // get_min
	if(k == 0) {
		return f[k] = (s[x1][x2][y1][y2] >= lo ? s[x1][x2][y1][y2] : f[k]);
	}
	for(int y = y1; y < y2; y ++)
		for(int i = 0; i < k; i ++) {
			f[k] = min(f[k], max(dfs(lo, x1, x2, y1, y, i), dfs(lo, x1, x2, y+1, y2, k-i-1)));
		}
	for(int x = x1; x < x2; x ++)
		for(int i = 0; i < k; i ++) {
			f[k] = min(f[k], max(dfs(lo, x1, x, y1, y2, i), dfs(lo, x+1, x2, y1, y2, k-i-1)));
		}
	return f[k];
}
void solve() {
    cin >> h >> w >> T;
    for(int i = 0; i < h; i ++)
    	for(int j = 0 ; j < w; j ++)
    		cin >> a[i][j];
    for(int x1 = 0; x1 < h; x1 ++) {
    	for(int x2 = x1; x2 < h; x2 ++) {
    		for(int y1 = 0; y1 < w; y1 ++) {
    			for(int y2 = y1; y2 < w; y2 ++) {
    				for(int x = x1; x <= x2; x ++) {
    					for(int y = y1; y <= y2; y ++) {
    						s[x1][x2][y1][y2] += a[x][y];
    					}
    				}
    				val.push_back(s[x1][x2][y1][y2]);
    			}
    		}
    	}
    }

    LL res = 1e18;
    for(auto lo : val) {
    	memset(dp, -1, sizeof dp);
    	LL tmx = dfs(lo, 0, h-1, 0, w-1, T);
    	if(tmx != 1e18) {
    		// cerr << tmx << ' ' << lo << '\n';
    		res = min(res, tmx-lo);
    	}
    }
    cout << res << '\n';
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