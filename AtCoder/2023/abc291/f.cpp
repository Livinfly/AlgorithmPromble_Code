#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10, M = 11, INF = 0x3f3f3f3f;

int n, m;
int f[N], g[N];
bool st[N][M];


void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j ++) {
            st[i][j+1] = (s[j]&1);
        }
    }
    for(int i = 1; i <= n; i ++)
        f[i] = g[i] = INF;
    f[1] = g[n] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m && i-j >= 1; j ++) {
            if(st[i-j][j]) {
                f[i] = min(f[i], f[i-j]+1);
            }
        }
    }
    for(int i = n; i >= 1; i --) {
        for(int j = 1; j <= m && i-j >= 1; j ++) {
            if(st[i-j][j]) {
                g[i-j] = min(g[i-j], g[i]+1);
            }
        }
    }
    // for(int i = 1; i <= n; i ++)
    //     cout << f[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++)
    //     cout << g[i] << " \n"[i == n];
    for(int k = 2; k < n; k ++) {
        int ans = INF;
        for(int i = max(1, k-m); i < k; i ++) { // 之前WA不是一定跳过k
            for(int j = k+1; j <= n && j-i <= m; j ++)
                if(st[i][j-i]) {
                    ans = min(ans, f[i]+g[j]+1);
                }
        }
        if(ans == INF) ans = -1;
        cout << ans << " \n"[k == n-1];
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