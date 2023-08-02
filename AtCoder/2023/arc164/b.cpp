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

const int N = 2e5+10;

int n, m;
int c[N];

void solve() {
    cin >> n >> m;
    vector<array<int, 2>> e(m);
    for(auto &[x, y] : e) {
        cin >> x >> y;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    dsu.init(n);
    for(auto [x, y] : e) {
        if(c[x] != c[y]) {
            dsu.merge(x, y);
        }
    }
    for(auto [x, y] : e) {
        if(c[x] == c[y]) {
            if(dsu.same(x, y)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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