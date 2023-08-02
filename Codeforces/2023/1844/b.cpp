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
    if(n == 1) {
        cout << "1\n";
        return;
    }
    if(n == 2) {
        cout << "2 1\n";
        return;
    }
    cout << 2 << ' ';
    int t = n-3;
    int lc = t/2, rc = t-lc;
    for(int i = 0, x = 4; i < lc; i ++, x ++) {
        cout << x << ' ';
    }
    cout << 1 << ' ';
    for(int i = 0, x = 4+lc; i < rc; i ++, x ++) {
        cout << x << ' ';
    }
    cout << 3 << '\n';
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