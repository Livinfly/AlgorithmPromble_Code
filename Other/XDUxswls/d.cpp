#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 501, MO = 998244353;

int n;
int f[N][(N+1)*N/2];

void solve() {
    cin >> n;
    for(int i = 0; i <= n; i ++) 
        f[i][0] = 1;
    for(int i = 1; i <= n; i ++) {
        int tmx = (i+1)*i/2;
        for(int j = 1; j <= tmx; j ++) {
            f[i][j] = (1LL*f[i][j] + f[i-1][j] + (j>=i ? f[i-1][j-i] : 0)) % MO;
        }
    }
    for(int i = 0; i < n; i ++) {
        int ans = 0;
        int k = min(i, n-i-1);
        k = (k+1)*k/2;
        for(int j = 0; j <= k; j ++) {
            ans = (1LL*ans + 1LL*f[i][j]*f[n-i-1][j]%MO)%MO;
        }
        cout << (2LL*ans%MO+MO)%MO << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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