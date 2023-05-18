#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 210;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL g[31][N][N], f[N], ff[N], ans[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[0][a][b] = c;
    }
    int T;
    cin >> T;
    auto floyd = [&](LL a[N][N], LL b[N][N]) {
        memset(ans, 0x3f, sizeof ans);
        for(int k = 1; k <= n; k ++)
            for(int i = 1; i <= n; i ++)
                for(int j = 1; j <= n; j ++)
                    ans[i][j] = min(ans[i][j], a[i][k] + b[k][j]);
        memcpy(a, ans, sizeof ans);
        return;
    };
    for(int i = 1; i < 31; i ++) {
        memcpy(g[i], g[i-1], sizeof g[i-1]);
        floyd(g[i], g[i-1]);
    }
    auto floyd1 = [&](LL a[N], LL b[N][N]) {
        memset(ff, 0x3f, sizeof ff);
        for(int k = 1; k <= n; k ++)
            for(int i = 1; i <= n; i ++)
                ff[i] = min(ff[i], a[k] + b[k][i]);
        memcpy(a, ff, sizeof ff);
        return;
    };
    int s, k;
    auto qpm = [&](int k) {
        memset(f, 0x3f, sizeof f);
        f[s] = 0;
        int kk = 0;
        while(k) {
            if(k & 1) floyd1(f, g[kk]);
            k >>= 1;
            kk ++;
        }
        return;
    };
    while(T --) {
        cin >> s >> k;
        qpm(k);
        for(int i = 1; i <= n; i ++) {
            cout << (f[i] == INF ? -1 : f[i]) << " \n"[i == n];
        }
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