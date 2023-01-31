#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

char g[N][N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int mx = (n+1)/2, my = (m+1)/2;
    int x = -1, y = -1;
    bool ok = false;
    for(int i = 1; i <= mx; i ++) {
        for(int j = 1; j <= my; j ++)
            if(i*j == k) {
                x = i-1, y = j-1;
                ok = true;
                break;
            }
        if(ok) break;
    }
    if(!ok) {
        cout << "Impossible\n";
        return;
    }
    // cout << x << ' ' << y << '\n';
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            g[i][j] = '.';
    for(int i = 1, j = 0; i < n && j < x; i += 2, j ++)
        for(int u = 0; u < m; u ++)
            g[i][u] = '#';
    for(int i = 1, j = 0; i < m && j < y; i += 2, j ++)
        for(int u = 0; u < n; u ++)
            g[u][i] = '#';
    for(int i = 0; i < n; i ++)
        cout << g[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}