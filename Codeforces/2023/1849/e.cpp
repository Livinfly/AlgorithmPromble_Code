#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 1e6+10;

int n;
int a[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sgt.build(1, 1, n);
    LL ans = 0;
    for(int i = 0; i+2 <= n; i ++) { // i..mn(x)..mx(y)..j
        int x, y, j;
        y = sgt.queryLess(1, i+2, n, a[i]);
        x = sgt.queryMin(1, i+1, y);
        j = sgt.query
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}