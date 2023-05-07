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
    vector<vector<int>> g(h);
    for(auto &v : g) v.resize(w);
    for(auto &v : g)
    	for(auto &x : v)
    		cin >> x;
    int ans = 0;
    set<int> st;
    function<void(int, int)> dfs = [&](int x, int y) {
    	if(st.count(g[x][y])) return;
    	if(x == h-1 && y == w-1) {
    		ans ++;
    		return;
    	}
    	st.insert(g[x][y]);
    	if(x+1 < h) dfs(x+1, y);
    	if(y+1 < w) dfs(x, y+1);
        st.erase(st.find(g[x][y]));
    };
    dfs(0, 0);
    cout << ans << '\n';
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