#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int a[N<<1], f[N<<1][N<<1];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n+1; i <= 2*n; i ++) a[i] = a[i-n];
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= 2*n; i ++) f[i][i] = 0;
    for(int i = 1; i <= 2*n-1; i ++) f[i][i+1] = 0;
    for(int len = 2; len <= n+1; len ++) {
        for(int l = 1; l <= n; l ++) {
            int r = l+len-1;
            for(int k = l; k <= r; k ++) {
                f[l][r] = min(f[l][r], f[l][k]+f[k][r]+(a[l]==a[r]));
            }
            // cout << l << ':' << r << ' ' << f[l][r] << '\n';
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        res = max(res, n-f[i][i+n]+1);
        // cout << i << ':' << f[i][i+n] << '\n';
    }
    res = min(res, n);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}