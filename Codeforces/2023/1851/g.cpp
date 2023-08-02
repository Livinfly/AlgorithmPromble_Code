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
    int leader(int x, bool compress = true) {
        if(x == fa[x]) return x;
        int root = leader(fa[x]);
        return compress ? fa[x] = root : root;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    bool merge(int x, int y, bool strict = true) {
        x = leader(x), y = leader(y);
        if(x == y) return false;
        if(!strict && siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return siz[leader(x)];
    }
}dsu;

void solve() {
    int n, m, q;
    cin >> n >> m;
    vector<int> h(n);
    for(auto &x: h) cin >> x;
    vector<array<int, 3>> e(m);
    for(auto &[w, x, y]: e) {
        cin >> x >> y;
        x--, y--;
        w = max(h[x], h[y]);
    }
    sort(all(e));
    cin >> q;
    vector<array<int, 4>> qry(q);
    for(int i = 0; i < q; i ++) {
        auto &[w, x, y, id] = qry[i];
        cin >> x >> y >> w;
        x--, y--;
        w += h[x];
        id = i;
    }
    sort(all(qry));
    vector<bool> ans(q);
    dsu.init(n);
    int j = 0;
    for(auto [w, x, y, id]: qry) {
        while(j < m && e[j][0] <= w) {
            dsu.merge(e[j][1], e[j][2], false);
            j++;
        }
        ans[id] = dsu.same(x, y);
    }
    for(auto x: ans) {
        if(x) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}