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

const int N = 20;
const LL INF = 0x3f3f3f3f3f3f3f3f;

mt19937 rnd(time(0));
int n;
int fa[N];
LL g[N][N], gg[N][N], f[N][N];
LL ans = INF;

double Rand(int l, int r) {
    return 1.0*rnd() / rnd.max() * (r-l) + l;
}
LL Calc() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] = gg[i][j];
        }
    }
    for(int k = 1; k <= n; k++) 
        for(int i = 1; i <= n; i++)  
            for(int j = 1; j <= n; j++) 
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    LL ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(f[i][j] == INF) return -1;
            ret += f[i][j];
        }
    }
    return ret;
}
bool check() {
    dsu.Init(n);
    for(int i = 1; i <= n; i ++) {
        dsu.Merge(fa[i], i);
    }
    return dsu.Size(1) == n;
}
LL SimulateAnneal(int root) {
    double t = 2.5e4;
    LL ret = Calc();
    while(t > 1e-9) {
        int u, v;
        do {
            u = Rand(1, n), v = Rand(1, n);
        } while(u == v || v == root);
        int tfa = fa[v];
        fa[v] = u;
        gg[tfa][v] = gg[v][tfa] = INF;
        gg[u][v] = gg[v][u] = g[u][v];
        
        LL nret = Calc();
        if(nret == -1) {
            fa[v] = tfa;
            gg[u][v] = gg[v][u] = INF;
            gg[tfa][v] = gg[v][tfa] = g[tfa][v];
            continue;
        }
        // if(nret == -1) {
        //     for(int i = 1; i <= n; i ++) {
        //         cerr << dsu.Size(i) << " \n"[i==n];
        //     }
        // }
        LL delta = nret - ret;
        // cerr << nret << ' ' << ret << ' ' << delta << '\n';
        if(delta < 0 || exp(-1.0*delta/t) > Rand(0, 1))
            ret = nret;
        else {
            fa[v] = tfa;
            gg[tfa][v] = gg[v][tfa] = g[tfa][v];
            gg[u][v] = gg[v][u] = INF;
        }
        t *= 0.998;
        // cerr << t << ' ' << ret << '\n';
    }
    return ret;
}
void solve() {
    srand(time(0));
    cin >> n;
    memset(g, 0x3f, sizeof(g));
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    else if(n == 2) {
        cout << g[1][2] << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j ++) fa[j] = i;
        memset(gg, 0x3f, sizeof gg);
        g[i][i] = 0;
        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            gg[i][j] = gg[j][i] = g[i][j];
        }
        ans = min(ans, SimulateAnneal(i));
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