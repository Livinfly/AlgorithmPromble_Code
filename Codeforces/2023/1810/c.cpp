#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    LL n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    LL res = c*(n-a.size());
    LL ans = c*a.size()+d;
    for(int i = 0; i < a.size(); i ++) {
        ans = min(ans, d*(a[i]-i-1)+c*((LL)a.size()-i-1));
    }
    // cout << res << ' ' << ans << '\n';
    cout << res + ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}
/*
1
5 2 3
1 1 1 3 3
*/