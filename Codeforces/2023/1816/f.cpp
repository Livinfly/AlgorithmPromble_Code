#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MO = 998244353;

LL n, m;
map<LL, int> f, g;

LL F(LL n) {
    if(f.count(n)) return f[n];
    if(n & 1) {
        // F((n-1)/2);
        f[n] = (2*F((n-1)/2)%MO+g[(n-1)/2])%MO;
        g[n] = g[(n-1)/2];
    }
    else {
        // F(n/2), F(n/2-1);
        f[n] = (2*F(n/2)%MO+2*F(n/2-1)%MO)%MO;
        g[n] = (g[n/2]+g[n/2-1])%MO;
    }
    return f[n];
}
void solve() {
    f[0] = 0, g[0] = 1;
    cin >> n >> m;
    if(m == 1) cout << n%MO << '\n';
    else if(m == 2) {
        cout << F(n) << '\n';
    }
    else {
        if(n & 1) cout << (n/2+1)%MO*((n/2+1)%MO)%MO << '\n';
        else cout << (n/2%MO)*((n/2+1)%MO)%MO << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}