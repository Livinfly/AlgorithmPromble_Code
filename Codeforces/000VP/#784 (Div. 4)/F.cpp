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
    vector<int> a(n), sum(2);
    for(auto &x : a) cin >> x;
    int l = 0, r = n-1;
    int res = 0;
    while(l <= r) {
        if(sum[0]+a[l] <= sum[1]+a[r]) sum[0] += a[l ++];
        else sum[1] += a[r --];
        if(sum[0] == sum[1]) res = max(res, l+n-r-1);
        // cout << sum[0] << ' ' << sum[1] << '\n';
    }
    cout << res << '\n';
    // cout << "----------\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}