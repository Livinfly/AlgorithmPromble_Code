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
    vector<int> fa, siz, sizE;

    void init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        sizE.resize(n+1, 0);
        for(int i = 1; i <= n; i ++) 
            fa[i] = i, siz[i] = 1;
    }
    int getFa(int x) {
        if(x == fa[x]) return x;
        return fa[x] = getFa(fa[x]);
    }
    bool same(int x, int y) {
        return getFa(x) == getFa(y);
    }
    bool merge(int x, int y) {
        x = getFa(x), y = getFa(y);
        if(x == y) return false;
        siz[x] += siz[y];
        sizE[x] += sizE[y] + 1;
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return siz[getFa(x)];
    }
}dsu;

void solve() {
    int n, m;
    cin >> n >> m;
    dsu.init(n);
    while(m --) {
    	int a, b;
    	cin >> a >> b;
    	if(dsu.same(a, b)) {
    		dsu.sizE[dsu.getFa(a)] ++;
    	}
    	else {
    		dsu.merge(a, b);
    	}
    }
    int ans = 0;
    vector<bool> vis(n+1, false);
    for(int i = 1; i <= n; i ++) {
    	int x = dsu.getFa(i);
    	if(!vis[x]) {
    		ans += dsu.sizE[x] - dsu.size(x) + 1;
    		vis[x] = true;
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