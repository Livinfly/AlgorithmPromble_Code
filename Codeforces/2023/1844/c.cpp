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
    int n;
    cin >> n;
    vector<int> c(n+2);
    bool st = false;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
        if(c[i] >= 0) {
            st = true;
        }
    }
    if(!st) {
        int ans = -1e9;
        for(int i = 1; i <= n; i ++) {
            ans = max(ans, c[i]);
        }
        cout << ans << '\n';
        return;
    }
    LL ans = 0, res = 0;
    for(int i = 1; i <= n; i += 2) {
        res += max(c[i], 0);
    }
    ans = max(ans, res);
    res = 0;
    for(int i = 2; i <= n; i += 2) {
        res += max(c[i], 0);
    }
    ans = max(ans, res);
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