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
    int n; cin >> n;
    vector<int> a(n+1), c(n+1);
    for(int i = 1; i <= n; i ++) cin >> c[i];
    int k; cin >> k;

    int p = 0, mn = 0;
    for(int i = 1; i <= n; i ++) {
        if(p == 0 || c[i] <= mn) p = i, mn = c[i];
    }
    if(!p) {
        for(int i = 0; i < n; i ++) {
            cout << 0 << " \n"[i+1 == n];
        }
        return;
    }
    a[0] += k/mn;
    while(true) {
        int r = k % mn, pp = p, mx = 0;
        for(int i = n; i > p; i --) {
            if(k > c[i] * r / (c[i]-c[p]) && r / (c[i]-c[p]) > mx) pp = i, mx = r / (c[i]-c[p]);
        }
        cerr << k << ' ' << pp << ' ' << c[pp] << ' ' << mx << '\n';
        if(!mx) break;
        a[pp] -= 1;
        k -= c[pp] * 1;
    }
    a[p] -= k/mn;
    for(int i = 0; i < n; i ++) {
        if(i) a[i] += a[i-1];
        cout << a[i] << " \n"[i+1 == n];
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}