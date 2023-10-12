// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    int n, x, y, z; cin >> n;
    bool ok = true;
    if(n % 3 != 0) {
        x = 1, y = 2, z = n-3;
        if(z <= 2) ok = false;
    }
    else {
        x = 1, y = 4, z = n-5;
        if(z <= 4) ok = false;
    }
    if(ok) {
        cout << "YES\n";
        cout << x << ' ' << y << ' ' << z << '\n';
    }
    else cout << "NO\n";
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}