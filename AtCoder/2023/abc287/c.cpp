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
    vector<int> deg(n);
    if(n-1 != m) {
    	cout << "No\n";
    	return;
    }
    while(m --) {
    	int a, b;
    	cin >> a >> b;
        a --, b --;
    	deg[a] ++, deg[b] ++;
        dsu.merge(a, b);
    }
    for(int i = 0; i < n; i ++) {
        if(deg[i] > 2) {
            cout << "No\n";
            return;
        }
    }
    if(dsu.size(0) != n) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
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