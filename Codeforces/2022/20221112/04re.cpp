#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    LL a, b, d, x = 0;
    cin >> a >> b >> d;
    a |= b;
    LL k = 0;
    while(d%2 == 0) {
        if(a&1) {
            cout << -1 << '\n';
            return;
        }
        a >>= 1;
        d >>= 1;
        k ++;
    }
    for(int i = 0; i < 30 && a; i ++, a >>= 1) {
        if((a&1) && !(x>>i&1))
            x += (d<<i);
    }
    cout << (x<<k) << '\n';
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