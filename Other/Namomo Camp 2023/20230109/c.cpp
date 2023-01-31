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
    vector<PII> a(n);
    for(auto &x : a) cin >> x.fi >> x.se;
    int xMx = a[0].fi, xMn = a[0].fi, yMx = a[0].se, yMn = a[0].se;
    LL sum = 0;
    for(int i = 1; i < n; i ++) {
        sum += abs(a[i].fi+a[i].se-a[i-1].fi-a[i-1].se);
        xMx = max(xMx, a[i].fi), xMn = min(xMn, a[i].fi);
        yMx = max(yMx, a[i].se), yMn = min(yMn, a[i].se);
    }
    sum += abs(a[0].fi+a[0].se-a[n-1].fi-a[n-1].se);
    cout << sum-2*(xMx-xMn+yMx-yMn) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    freopen("intel.in", "r", stdin);
    freopen("intel.out ", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*
不要被计算几何的外表骗了，实际只是脑经急转弯 —— dls

外面能看到的部分就是上下左右四个方向
就是x最大最小值、y最大最小值处理一下的值
*/