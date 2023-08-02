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
    LL s, k;
    cin >> s >> k;
    if(!s) {
        cout << "0\n";
        return;
    }
    LL p = 0, ans = 0, x = 1e9;
    for(p = 0; p < k; p ++) {
        ans = max(ans, s * (k-p));
        if(s * (k-p) == 1252047198518668448LL) {
            cerr << s << ' ' << (k-p) << '\n';
            x = min(x, p);
        }
        if(s%10) {
            s += s%10;
        }
        else {
            break;
        }
    }
    cerr << x << '\n';
    // ans = max(ans, s * (k-p));
    // cerr << k-p << '\n';
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