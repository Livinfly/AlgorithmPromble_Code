#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, INF = 1e9;

vector<array<int, 2>> e[N<<1];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
    	int s;
    	cin >> s;
    	for(int j = 0; j < s; j ++) {
    		int x;
    		cin >> x;
    		e[i+m].push_back({x, 0});
    		e[x].push_back({i+m, 1});
    	}
    }
    vector<int> d(n+m+1, INF);
    auto bfs = [&]() {
    	d[1] = 0;
    	deque<int> q;
    	q.push_back(1);
    	while(q.size()) {
    		auto u = q.front();
    		if(u == m) break;
    		q.pop_front();
    		for(auto [v, w] : e[u]) {
    			if(d[u] + w < d[v]) {
    				d[v] = d[u] + w;
	    			if(w == 0) {
	    				q.push_front(v);
	    			}
	    			else {
	    				q.push_back(v);
	    			}
    			}
    		}
    	}
    };
    bfs();
    if(d[m] == INF) {
    	cout << -1 << '\n';
    }
    else {
    	cout << d[m]-1 << '\n';
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