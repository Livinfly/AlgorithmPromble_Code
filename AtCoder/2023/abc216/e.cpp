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
    int n, k; cin >> n >> k;
    vector<int> ve(n);
    for(auto &x: ve) cin >> x;

    auto f = [&](int mid) {
        LL ret = 0;
        for(auto x: ve) {
            ret += max(x-mid+1, 0);
        }
        return ret;
    };
    int l = 0, r = 2e9;
    while(l < r) {
        int mid = (1LL*l+r+1) >> 1;
        if(f(mid) >= k) l = mid;
        else r = mid-1;
    }
    LL ans = 0;
    for(auto x: ve) { // [r, x]
        if(x >= r) ans += (1LL*r+x)*(x-r+1)/2;
    }
    ans -= 1LL*(f(r)-k) * r;
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}