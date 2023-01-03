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
    vector<int> a(n*m);
    vector<int> col1(n+m), col2(n+m);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> a[i*m+j], 
            col1[i-j+m] += a[i*m+j], 
            col2[i+j] += a[i*m+j];
    int res = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            res = max(res, col1[i-j+m]+col2[i+j]-a[i*m+j]);
    cout << res << '\n';
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