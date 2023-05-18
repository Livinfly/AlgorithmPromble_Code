#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

vector<int> e[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
    	int a, b;
    	cin >> a >> b;
    	e[a].push_back(b);
    }
    int ans = 0;
    vector<bool> vis;
    function<void(int)> dfs = [&](int u){
    	vis[u] = true;
    	ans ++;
    	for(auto v : e[u]) {
    		if(!vis[v]) {
				dfs(v);
    		}
    	}
    };
    for(int i = 1; i <= n; i ++) {
    	vis.assign(n+1, false);
    	dfs(i);
    }
    cout << ans-m-n << '\n';
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