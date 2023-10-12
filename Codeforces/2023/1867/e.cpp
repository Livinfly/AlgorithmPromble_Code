// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    int n, k; cin >> n >> k;
    int i = 1, ans = 0;
    while(i+k-1 <= n) { // [i, i+k-1]
        cout << "? " << i << endl;
        int ret; cin >> ret;
        ans ^= ret;
        i += k;
    }
    int t = n-i+1;
    cout << "? " << n - k - t/2 + 1 << endl;
    int ret; cin >> ret; 
    ans ^= ret;
    cout << "? " << n - k + 1 << endl;
    cin >> ret;
    ans ^= ret;
    cout << "! " << ans << endl;
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