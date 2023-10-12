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

void solve() {
    LL m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    if(k*ak > m) m %= k;
    else m -= k*ak;
    // if(a1 >= m%k) a1 -= m%k, m -= m%k;
    // cerr << m << ' ' << a1 << '\n';
    // 1 2 3
    LL ans = max(m-a1, 0LL) / k + max(m-a1, 0LL) % k;
    if(a1 >= m%k) a1 -= m%k, m -= m%k;
    ans = min(ans, max(m/k-a1/k, 0LL) + max(m%k - a1%k, 0LL));
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}