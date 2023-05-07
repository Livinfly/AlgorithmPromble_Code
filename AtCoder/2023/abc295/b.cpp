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
    int r, c;
    cin >> r >> c;
    vector<string> g(r);
    for(auto &s : g) {
    	cin >> s;
    }
    for(int i = 0; i < r; i ++) {
    	for(int j = 0; j < c; j ++) {
    		if(g[i][j] >= '1' && g[i][j] <= '9') {
    			for(int x = 0; x < r; x ++) {
    				for(int y = 0; y < c; y ++) {
    					if(g[x][y] == '#' && abs(x-i)+abs(y-j) <= g[i][j]-'0') {
    						g[x][y] = '.';
    					}
    				}
    			}
    		}
    	}
    }
    for(auto &s : g) 
    	for(auto &x : s) 
    		if(x >= '1' && x <= '9')
    			x = '.';
    for(auto s : g)
    	cout << s << '\n';
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