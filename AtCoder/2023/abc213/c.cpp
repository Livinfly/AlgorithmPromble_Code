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
    int h, w, n;
    cin >> h >> w >> n;
    vector<PII> p(n);
    vector<int> xx, yy;
    for(auto &[x, y]: p) {
        cin >> x >> y;
        xx.push_back(x), yy.push_back(y);
    }
    sort(all(xx)), sort(all(yy));
    xx.resize(unique(all(xx)) - xx.begin());
    yy.resize(unique(all(yy)) - yy.begin());
    for(auto [x, y]: p) {
        x = lower_bound(all(xx), x) - xx.begin() + 1;
        y = lower_bound(all(yy), y) - yy.begin() + 1;
        cout << x << ' ' << y << '\n';
    }
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