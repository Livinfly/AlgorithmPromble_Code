#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;

void solve() {
    int n;
    cin >> n;
    map<int, LL, greater<int>> sr, sc;
    map<PII, int> val;
    for(int i = 0; i < n; i ++) {
        int r, c, x;
        cin >> r >> c >> x;
        sr[r] += x, sc[c] += x;
        val[{r, c}] = x;
    }
    // sort by sum-val
    vector<PLI> R, C;
    for(auto [r, rx] : sr) {
        R.emplace_back(rx, r);
    }
    for(auto [c, cx] : sc)
        C.emplace_back(cx, c);
    sort(all(R), greater<PLI>());
    sort(all(C), greater<PLI>());
    LL res = 0;
    for(auto [rx, r] : R)
        for(auto [cx, c] : C) {
            res = max(res, rx+cx-val[{r, c}]);
            if(val[{r, c}] == 0) {
                break;
            }
        }
    cout << res << '\n';
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