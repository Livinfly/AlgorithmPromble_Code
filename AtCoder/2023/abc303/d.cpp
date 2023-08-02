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
    const LL INF = 1e18;
    LL x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<array<LL, 2>> f(n+1, {INF, INF});
    f[0][0] = 0, f[0][1] = z;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'a') {
            f[i][0] = min({f[i-1][0]+x, f[i-1][1]+z+x, f[i-1][1]+y+z});
            f[i][1] = min({f[i-1][1]+y, f[i-1][0]+x+z, f[i-1][0]+z+y});
        }
        else {
            f[i][1] = min({f[i-1][1]+x, f[i-1][0]+z+x, f[i-1][0]+y+z});
            f[i][0] = min({f[i-1][0]+y, f[i-1][1]+x+z, f[i-1][1]+z+y});
        }
    }
    cout << min(f[n][0], f[n][1]) << '\n';
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