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
    int n, m;
    cin >> n >> m;
    vector<string> c(n), d(m);
    for(auto &s : c) cin >> s;
    for(auto &s : d) cin >> s;
    int p0;
    cin >> p0;
    map<string, int> mp;
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        mp[d[i]] = x;
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(mp.count(c[i])) {
            ans += mp[c[i]];
        }
        else {
            ans += p0;
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}