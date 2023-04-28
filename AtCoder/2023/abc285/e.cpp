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
    vector<LL> a(n+2), s(n+2), val(n+2), f(n+2);
    for(int i = 1; i <= n; i ++) 
        cin >> a[i], s[i] = s[i-1]+a[i];
    for(int i = 1; i <= n; i ++) {
        val[i] = s[i/2]*2 + ((i%2 == 0) ? 0 : a[i/2+1]); // 加括号
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j < i; j ++)
            f[i] = max(f[i], f[j]+val[i-j-1]);
    LL res = 0;
    for(int i = 1; i <= n; i ++) {
        res = max(res, f[i]+val[n-i]);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}