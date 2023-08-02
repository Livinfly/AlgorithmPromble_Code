#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10, M = 2e5+10;

struct Backtrace {
    int x, y, siz;
}stkBack[M];
int top;

int n, m, k;
array<int, 2> rec[M];

struct DSU {
    vector<int> fa, siz;

    void init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        for(int i = 0; i <= n; i ++) 
            fa[i] = i, siz[i] = 1;
    }
    int leader(int x, bool compress = false) {
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

        stkBack[++top] = {x, y, siz[x]};

        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return siz[leader(x)];
    }
}dsu;

struct Info {
    int l, r;
    vector<int> id;
};

struct SegmentTree {
    Info tr[N<<2];
    #define ls(u) (u<<1)
    #define rs(u) (u<<1|1)
    void build(int u, int l, int r) {
        if(l == r) {
            tr[u] = {l, r};
            return;
        }
        tr[u] = {l, r};
        int mid = l+r >> 1;
        build(ls(u), l, mid), build(rs(u), mid+1, r);
    }
    void modify(int u, int l, int r, int x) {
        int ll = tr[u].l, rr = tr[u].r;
        if(l <= ll && rr <= r) {
            tr[u].id.push_back(x);
            return;
        }
        int mid = ll+rr >> 1;
        if(l <= mid) modify(ls(u), l, r, x);
        if(r > mid) modify(rs(u), l, r, x);
    }
    #undef ls
    #undef rs
}sgt;

void work(int u) {
    int ttop = top;
    bool ok = true;
    auto p = sgt.tr[u];
    int l = p.l, r = p.r;
    for(auto id : p.id) {
        auto [x, y] = rec[id];
        dsu.merge(x, y+n, false);
        dsu.merge(y, x+n, false);
        if(dsu.same(x, y)) {
            for(int i = l; i <= r; i ++) {
                cout << "No\n";
            }
            ok = false;
            break;
        }
    }
    if(ok) {
        if(l == r) {
            cout << "Yes\n";
        }
        else {
            work(u<<1), work(u<<1|1);
        }
    }
    while(top > ttop) {
        auto [x, y, siz] = stkBack[top--];
        dsu.siz[x] = siz, dsu.fa[y] = y;
    }
}
void solve() {
    cin >> n >> m >> k;
    dsu.init(2*n);
    sgt.build(1, 1, k);
    for(int i = 0; i < m; i ++) {
        auto &[x, y] = rec[i];
        int l, r;
        cin >> x >> y >> l >> r;
        sgt.modify(1, ++l, r, i);
    }
    work(1);
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