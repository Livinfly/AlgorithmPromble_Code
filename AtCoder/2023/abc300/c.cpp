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
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for(auto &s : g) 
    	cin >> s;
    int n = min(h, w);
    vector<int> ans(n);
    auto check = [&](int x, int y, int u) {
    	for(int i = 1; i <= u; i ++)
    		if(g[x+i][y+i] != '#' || g[x+i][y-i] != '#' ||
    			g[x-i][y+i] != '#' || g[x-i][y-i] != '#')
    			return false;
    	bool ok = (x+u+1 >= h || y+u+1 >= w || g[x+u+1][y+u+1] == '.') ||
                (x+u+1 >= h || y-u-1 < 0 || g[x+u+1][y-u-1] == '.') ||
                (x-u-1 < 0 || y+u+1 >= w || g[x-u-1][y+u+1] == '.') ||	
                (x-u-1 < 0 || y-u-1 < 0 || g[x-u-1][y-u-1] == '.');
    	return ok;
    };
    for(int u = 1; u <= n; u ++)
	    for(int i = u; i < h-u; i ++)
	    	for(int j = u; j < w-u; j ++) {
	    		if(g[i][j] == '#' && check(i, j, u)){
                    // cout << i << ' ' << j << ' ' << check(i, j, u) << '\n';
	    			ans[u-1] ++;
                }
	    	}
	for(auto x : ans) 
		cout << x << ' ';
	cout << '\n';
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