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
    LL n, m; cin >> n >> m; // int, LL ??
    vector<LL> a(n), b(m);
    for(auto &x: a) cin >> x;
    LL orsum = 0;
    for(auto &x: b) {
        cin >> x;
        orsum |= x;
    }
    LL ans1 = 0, ans2 = 0;
    for(auto x: a) {
        ans1 ^= (x | orsum);
    }
    for(auto x: a) {
        ans2 ^= x;
    }
    if(ans1 > ans2) swap(ans1, ans2);
    cout << ans1 << ' ' << ans2 << '\n';
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