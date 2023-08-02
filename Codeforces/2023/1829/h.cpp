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

const int MO = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<array<int, 64>> f(n);
    for(auto &x: a) cin >> x;
    for(int i = 0; i < n; i ++) {
        if(!i) {
            f[i][a[i]] = 1;
            continue;
        }
        for(int j = 0; j < 64; j ++) {
            f[i][j] = (f[i][j] + f[i-1][j]) % MO;
            f[i][j&a[i]] = (f[i][j&a[i]] + f[i-1][j]) % MO;
        }
        f[i][a[i]] = (f[i][a[i]] + 1) % MO;
    }
    int ans = 0;
    for(int i = 0; i < 64; i ++) {
        if(__builtin_popcount(i) == k) {
            ans = (ans + f[n-1][i]) % MO;
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
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}