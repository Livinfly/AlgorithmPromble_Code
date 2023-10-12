// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 1010, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], len[N][N], lastp[N*N];

void solve() {
    // cerr << '\n';
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            len[i][j] = INF;
        }
    for(int i = 1; i <= min(n, m); i ++) {
        int a = n, b = min(n, m)-i+1;
        while(a >= 1 && b >= 1) {
            // cerr << a << ' ' << b << ' ' << g[a][b] << '\n';
            if(g[a][b] == g[a+1][b+1]) {
                len[a][b] = len[a+1][b+1]+1;
            }
            else {
                len[a][b] = 1;
            }
            a--, b--;
        }
        a = i, b = m;
        while(a >= 1 && b >= 1) {
            if(g[a][b] == g[a+1][b+1]) {
                len[a][b] = len[a+1][b+1]+1;
            }
            else {
                len[a][b] = 1;
            }
            a--, b--;
        }
    }
    for(int i = 1; i <= n; i ++) {
        int mn = 0;
        for(int j = m; j >= 1; j --) {
            len[i][j] = min(len[i][j], mn+1);
            mn = min(mn, len[i][j])+1;
        }
    }
    for(int i = 1; i <= m; i ++) {
        int mn = 0;
        for(int j = n; j >= 1; j --) {
            len[j][i] = min(len[j][i], mn+1);
            mn = min(mn, len[j][i])+1;
        }
    }
    int t;
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= 1; j --) {
            t = lastp[g[i][j]] - j;
            if(lastp[g[i][j]] == -1) t = m+1-j;
            len[i][j] = (t < len[i][j] ? t : len[i][j]);
            lastp[g[i][j]] = j;
            // cerr << "len[" << i << "][" << j << "] = " << len[i][j] << '\n';
            // if(i == 1 && j == 1) {
            //     cerr << i+len[i][j] << '\n';
            // }
            for(int k = i+1; k < i+len[i][j]; k ++) {
                if(lastp[g[k][j]] != -1) {
                    len[i][j] = (k-i < len[i][j] ? k-i : len[i][j]);
                    break;
                }
                lastp[g[k][j]] = 0;
            }
            for(int k = i+1; k < i+len[i][j]; k ++) {
                lastp[g[k][j]] = -1;
            }
        }
        for(int j = 1; j <= m; j ++) lastp[g[i][j]] = -1;
    }
    LL ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cerr << "len[" << i << "][" << j << "] = " << len[i][j] << '\n';
            ans += len[i][j];
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
    memset(lastp, -1, sizeof lastp);
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}