// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

vector<int> dval;

struct DSU {
    vector<int> fa, siz;

    void init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        for(int i = 0; i <= n; i ++) {
            fa[i] = i, siz[i] = dval[i] - (i ? dval[i-1] : 0);
        }
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
    int L, q; cin >> L >> q;
    dval.pb(L);
    vector<array<int, 2>> rec(q);
    for(auto &[op, x]: rec) {
        cin >> op >> x;
        if(op == 1) dval.pb(x);
    }
    sort(all(dval));
    dval.resize(unique(all(dval)) - dval.begin());
    for(auto &[op, x]: rec) {
        if(op == 1) {
            x = lower_bound(all(dval), x) - dval.begin();
        }
    }

    reverse(all(rec));

    dsu.init(dval.size());

    vector<int> ans;
    for(auto [op, x]: rec) {
        if(op == 1) {
            dsu.merge(x+1, x);
        }
        else {
            ans.pb(dsu.size(lower_bound(all(dval), x)-dval.begin()));
        }
    }
    reverse(all(ans));
    for(auto x: ans) cout << x << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}