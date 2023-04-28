#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

struct DSU {// int / LL
    vector<int> fa, siz;

    void Init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        for(int i = 1; i <= n; i ++) 
            fa[i] = i, siz[i] = 1;
    }
    int GetFa(int x) {
        if(x == fa[x]) return x;
        return fa[x] = GetFa(fa[x]);
    }
    bool Same(int x, int y) {
        return GetFa(x) == GetFa(y);
    }
    bool Merge(int x, int y) {
        x = GetFa(x), y = GetFa(y);
        if(x == y) return false;
        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }
    int Size(int x) {
        return siz[GetFa(x)];
    }
}dsu;
struct FenwickTree { // int / LL
    int n;
    vector<int> a;
    void Init(int n) {
        this->n = n;
        a.assign(n+1, 0);
    }
    int Lowbit(int x) {
        return x & -x;
    }
    void Add(int x, int v) {
        for( ; x <= n; x += Lowbit(x))
            a[x] += v;
    }
    int Sum(int x) {
        int ans = 0;
        for( ; x; x -= Lowbit(x))
            ans += a[x];
        return ans;
    }
    int RangeSum(int l, int r) {
        return Sum(r) - Sum(l-1);
    }
}fen;

vector<int> eMx[N], eMn[N], reMx[N], reMn[N];
int tms, dfn[N], depMx[N], sizMx[N], depMn[N];
int n;
LL A, B, C;

void dfs1(int u) {
    dfn[u] = ++tms;
    sizMx[u] = 1;
    A += depMx[u];
    for(auto v : reMx[u]) {
        depMx[v] = depMx[u]+1;
        dfs1(v);
        sizMx[u] += sizMx[v];
    }
}
void dfs2(int u) {    
    B += depMn[u];
    C += fen.RangeSum(dfn[u], dfn[u]+sizMx[u]-1);
    fen.Add(dfn[u], 1);
    for(auto v : reMn[u]) {
        depMn[v] = depMn[u]+1;
        dfs2(v);
    }
    fen.Add(dfn[u], -1);
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        eMx[b].push_back(a);
        eMn[a].push_back(b);
    }
    
    dsu.Init(n);
    for(int u = 1; u <= n; u ++) {
        for(auto v : eMx[u]) {
            v = dsu.GetFa(v); // 下面放还是要放当前dsu的祖先
            dsu.Merge(u, v);
            reMx[u].push_back(v);
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << i << " : ";
    //     for(auto v : reMx[i])
    //         cout << v << ' ';
    //     cout << endl;
    // }

    dsu.Init(n);
    for(int u = n; u > 0; u --) {
        for(auto v : eMn[u]) {
            v = dsu.GetFa(v); // 下面放还是要放当前dsu的祖先
            dsu.Merge(u, v);
            reMn[u].push_back(v);
        }
    }

    fen.Init(n);
    dfs1(n);
    dfs2(1);
    LL ans = A+B-2*C;
    cout << ans << '\n';
    int m;
    cin >> m;
    while(m --) {
        int x;
        cin >> x;
        // 所有的点 与 新加入的点 的路径最大都是新加入的点
        // 有depMn[n]个点，满足最小值为这个点，得到只满足一个条件的数量。
        depMn[++ n] = depMn[x]+1;
        ans += (n-1)-depMn[n];
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}