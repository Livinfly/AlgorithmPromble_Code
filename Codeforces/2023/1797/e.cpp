#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10, M = 5e6+10;

// dep -> 25+-, fa[][6]
int idp, prime[M], phi[M], fa[M][6], dep[M];
bool vis[M];
int a[N];
int n, m;

void Sieve(int n) {
    for(int i = 2; i <= n; i ++) {
        if(!vis[i]) prime[idp ++] = i, phi[i] = i-1;
        for(int j = 0; prime[j] <= n/i; j ++) {
            int t = i*prime[j];
            vis[t] = true;
            if(i % prime[j] == 0) {
                phi[t] = phi[i]*prime[j];
                break;
            }
            else {
                phi[t] = phi[i]*(prime[j]-1);
            }
        }
    }
    // for(int i = 1; i <= 10; i ++)
    //     cout << i << ' ' << phi[i] << '\n';
}
void BuildPhiTree(int n) {
    dep[1] = 1;
    for(int k = 0; k < 6; k ++) fa[1][k] = 1;
    for(int i = 2; i <= n; i ++) {
        dep[i] = dep[phi[i]] + 1;
        fa[i][0] = phi[i];
        for(int k = 1; k < 6; k ++)
            fa[i][k] = fa[fa[i][k-1]][k-1];
    }
}
int LCA(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int k = 5; k >= 0; k --) 
        if(dep[fa[x][k]] >= dep[y])
            x = fa[x][k];
    if(x == y) return x;
    for(int k = 5; k >= 0; k --) 
        if(fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}
struct Info {
    int l, r;
    int lca, ans;
    bool root;
};
struct SegTree {
    Info tr[N<<2];
    #define ls(u) (u<<1)
    #define rs(u) (u<<1|1)

    void PushUp(int u) {
        tr[u].lca = LCA(tr[ls(u)].lca, tr[rs(u)].lca);
        tr[u].ans = tr[ls(u)].ans + tr[rs(u)].ans +
                    (tr[ls(u)].r-tr[ls(u)].l+1) * (dep[tr[ls(u)].lca]-dep[tr[u].lca]) +
                    (tr[rs(u)].r-tr[rs(u)].l+1) * (dep[tr[rs(u)].lca]-dep[tr[u].lca]);
        tr[u].root = tr[ls(u)].root && tr[rs(u)].root;
    }
    void Build(int u, int l, int r) {
        if(l == r) {
            tr[u] = {l, r, a[r], 0, a[r] == 1};
            return;
        }
        tr[u] = {l, r};
        int mid = l+r >> 1;
        Build(ls(u), l, mid), Build(rs(u), mid+1, r);
        PushUp(u);
    }
    void Modify(int u, int l, int r) {
        if(tr[u].root) return;
        if(tr[u].l == tr[u].r) {
            tr[u].lca = fa[tr[u].lca][0];
            tr[u].root = tr[u].lca == 1;
            return;
        }
        int mid = tr[u].l+tr[u].r >> 1;
        if(l <= mid) Modify(ls(u), l, r);
        if(r > mid) Modify(rs(u), l, r);
        PushUp(u);
    }
    int QueryLCA(int u, int l, int r) {
        if(l <= tr[u].l && tr[u].r <= r) return tr[u].lca;
        int mid = tr[u].l+tr[u].r >> 1;
        int lca1 = 0, lca2 = 0;
        if(l <= mid) lca1 = QueryLCA(ls(u), l, r);
        if(r > mid) lca2 = QueryLCA(rs(u), l, r);
        // cout << tr[u].l << ' ' << tr[u].r << " : " << lca1 << ' ' << lca2 << ' ' << LCA(lca1, lca2) << '\n';
        if(!lca1) return lca2;
        if(!lca2) return lca1;
        return LCA(lca1, lca2);
    }
    int QueryAns(int u, int l, int r, int lca) {
        if(l <= tr[u].l && tr[u].r <= r) return tr[u].ans + (tr[u].r-tr[u].l+1)*(dep[tr[u].lca]-dep[lca]);
        int mid = tr[u].l+tr[u].r >> 1;
        int ans = 0;
        if(l <= mid) ans += QueryAns(ls(u), l, r, lca);
        if(r > mid) ans += QueryAns(rs(u), l, r, lca);
        return ans;
    }
    #undef ls
    #undef rs
}sgt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    Sieve(M-10);
    BuildPhiTree(M-10); 
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sgt.Build(1, 1, n);
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            sgt.Modify(1, l, r);
        }
        else {
            int lca = sgt.QueryLCA(1, l, r);
            // cout << lca << '\n';
            cout << sgt.QueryAns(1, l, r, lca) << '\n';
        }
    }

    return 0;
}