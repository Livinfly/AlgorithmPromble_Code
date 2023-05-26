#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct DSU {
    vector<int> fa, siz;

    void init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        for(int i = 0; i <= n; i ++) 
            fa[i] = i, siz[i] = 1;
    }
    int leader(int x) {
        if(x == fa[x]) return x;
        return fa[x] = leader(fa[x]);
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    bool merge(int x, int y) {
        x = leader(x), y = leader(y);
        if(x == y) return false;
        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return siz[leader(x)];
    }
}dsu;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> e(M);
    for(auto &[u, v] : e) {
    	cin >> u >> v;
    	u --, v --;
    }
    vector<bool> must(M);
    int K;
    cin >> K;
    for(int i = 0; i < K; i ++) {
    	int x;
    	cin >> x;
    	x --;
    	must[x] = true;
    }
    vector<int> deg(N), cnt(N);
    dsu.init(N);
    for(int i = 0; i < M; i ++) {
    	auto [u, v] = e[i];
    	if(must[i]) {
    		deg[u] ++, deg[v] ++;
    	}
    	else {
    		dsu.merge(u, v);
    	}
    }
    for(int i = 0; i < N; i ++) {
    	cnt[dsu.leader(i)] += deg[i];
    }
    int odd = 0;
    for(int i = 0; i < N; i ++) {
    	if(dsu.leader(i) == i && cnt[i] % 2) {
    		odd ++;
    	}
    }
    cout << (!odd || odd == 2 ? "Yes" : "No") << '\n';
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