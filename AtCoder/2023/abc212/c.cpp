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
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(all(a));
    int mn = 1e9;
    while(m --) {
        int x;
        cin >> x;
        auto it = upper_bound(all(a), x);
        // cerr << *it << '\n';
        if(it != a.end()) {
            mn = min(mn, *it - x);
        }
        if(it != a.begin()) {
            mn = min(mn, x - *(--it));
        }
    }
    cout << mn << '\n';
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