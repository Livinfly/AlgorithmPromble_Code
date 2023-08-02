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
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> g(H);
    for(auto &s : g) cin >> s;
    vector<PII> p;
	PII S, E;
	for(int i = 0; i < H; i ++) {
		for(int j = 0; j < W; j ++) {
			if(g[i][j] == 'o') {
				p.emplace_back(i, j);
			}
			else if(g[i][j] == 'S') {
				S = {i, j};
			}
			else if(g[i][j] == 'G') {
				E = {i, j};
			}
		}
	}
	int cnt = p.size();
	const int INF = 1e9;
	int dxy[4][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
	};
	auto bfs = [&](PII p) {
		vector<vector<int>> ret(H, vector<int>(W, INF));
		queue<PII> q;
		q.push(p);
		ret[p.fi][p.se] = 0;
		while(q.size()) {
			auto [x, y] = q.front();
			q.pop();
			for(int i = 0; i < 4; i ++) {
				int a = x + dxy[i][0], b = y + dxy[i][1];
				if(a < 0 || a >= H || b < 0 || b >= W) continue;
				if(g[a][b] == '#') continue;
				if(ret[a][b] == INF) {
					ret[a][b] = ret[x][y] + 1;
					q.emplace(a, b);
				}
			}
		}
		return ret;
	};

	vector<vector<vector<int>>> d(cnt);
	for(int i = 0; i < cnt; i ++) {
		d[i] = bfs(p[i]);
	}
	int tot = (1 << cnt);
	vector<vector<int>> dp(tot, vector<int>(cnt, INF));
	for(int i = 0; i < cnt; i ++) {
		auto [x, y] = S;
		dp[1 << i][i] = d[i][x][y];
	}
	for(int i = 0; i < tot; i ++) {
		for(int from = 0; from < cnt; from ++) {
			if(dp[i][from] == INF) continue;
			for(int to = 0; to < cnt; to ++) {
				// if(i >> to & 1) continue;
				auto [a, b] = p[to];
				dp[i | 1 << to][to] = min(dp[i | 1 << to][to], dp[i][from] + d[from][a][b]);
			}
		}
	}
	// for(int i = 0; i < cnt; i ++) {
	// 	cout << i << ':' << '\n';
	// 	for(int j = 0; j < H; j ++) {
	// 		for(int k = 0; k < W; k ++) {
	// 			cout << d[i][j][k] << " \n"[k+1 == W];
	// 		}
	// 	}
	// 	cout << '\n';
	// }
	int ans = -1;
	auto [x, y] = E;
	if(bfs(S)[x][y] <= T) ans = 0;
	for(int i = 0; i < tot; i ++) {
		for(int from = 0; from < cnt; from ++) {
			if(dp[i][from] + d[from][x][y] <= T) {
				int tcnt = 0;
				for(int j = i; j; j -= j & -j, tcnt ++);
				ans = max(ans, tcnt);
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