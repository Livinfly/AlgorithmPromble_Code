#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, INF = 0x3f3f3f3f;

vector<PII> e[N];

void solve() {
    int n, m;
    cin >> n >> m;
    while(m --) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	e[a].push_back({b, c});
    }
    vector<vector<int>> d(n+1, vector<int>(n+1, INF));
    vector<vector<int>> dd(n+1, vector<int>(n+1, INF));
    vector<bool> vis;
   	int ans = INF*2; // max 2e9
  	auto dijkstra = [&](int x) {
        set<PII> heap;
  		auto &dis = d[x];
        auto &ddis = dd[x];
  		dis[x] = 0;
        heap.insert({0, x});
  		while(heap.size()) {
  			auto [_, u] = *heap.begin();
            heap.erase(heap.begin());
            if(vis[u]) continue;
  		    vis[u] = true;
  			for(auto [v, w] : e[u]) {
  				for(auto ww : {dis[u], ddis[u]}) {
                    ww += w;
                    if(ww < dis[v]) {
                        ddis[v] = dis[v];
                        dis[v] = ww;
                        heap.insert({dis[v], v});
                    }
                    else if(ww < ddis[v]) {
                        ddis[v] = ww;
                    }
                }
  			}
  		}
  	};
   	for(int i = 1; i <= n; i ++) {
   		vis.assign(n+1, false);
   		dijkstra(i);
   	}
   	for(int x = 1; x <= n; x ++) {
   		for(int y = 1; y <= n; y ++) {
            if(x != y) {
                ans = min(1LL*ans, 1LL*d[1][x] + d[y][n] + d[x][y] + dd[x][y]);
                // cout << d[x][y] << ' ' << dd[x][y] << '\n';
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