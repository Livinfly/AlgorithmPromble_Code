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
    vector<int> a(1001);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    int res = -1;
    for(int i = 1; i <= 1000; i ++)
        for(int j = 1; j <= 1000; j ++) 
            if(__gcd(i, j) == 1 && a[i] && a[j]) {
                res = max(res, a[i]+a[j]);
            }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}