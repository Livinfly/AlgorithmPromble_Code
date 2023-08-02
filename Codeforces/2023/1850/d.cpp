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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(all(a));
    int ans = 0, res = 1;
    for(int i = 1; i < n; i ++) {
        if(a[i] - a[i-1] <= k) {
            res ++;
        }
        else {
            ans = max(ans, res);
            res = 1;
        }
    }
    ans = max(ans, res);
    cout << n-ans << '\n';
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