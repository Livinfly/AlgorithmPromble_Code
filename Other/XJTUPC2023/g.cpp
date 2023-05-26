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
    vector<bool> vis((int)1e7);
    vector<int> f(n);
    f[0] = 0;
    vis[0] = true;
    for(int i = 1, x = 1; i < n; i ++) {
        while(vis[x]) x ++;
        f[i] = x;
        for(int j = 0; j <= i; j ++) {
            for(int k = 0; k <= i; k ++) {
                vis[f[i]+f[j]-f[k]] = true;
            }
        }
    }
    cout << n-1 << '\n';
    for(int i = 1; i < n; i ++) {
        cout << i << ' ' << i+1 << ' ' << f[i]-f[i-1] << '\n';
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