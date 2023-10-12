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
    int n, p; cin >> n >> p;
    vector<PII> a(n);
    for(auto &[x, y]: a) cin >> y;
    for(auto &[x, y]: a) cin >> x;
    // cost, num
    sort(all(a));
    LL ans = 0, now = 0;
    for(int i = 0; i < n; i ++) {
        if(now < i && a[now].fi < p && a[now].se > 0) ans += a[now].fi, a[now].se--;
        else ans += p;
        while(now < i && (!a[now].se || a[now].fi >= p)) now++;
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}