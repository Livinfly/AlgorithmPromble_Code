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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    vector<vector<int>> f(n, vector<int>(2));
    for(auto &x : a) {
        for(auto &y : x) {
            cin >> y;
        }
    }
    f[0][0] = f[0][1] = 1;
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j < 2; j ++)
            for(int k = 0; k < 2; k ++) {
                if(a[i-1][j] != a[i][k]) {
                    f[i][k] = ((LL)f[i][k]+f[i-1][j])%MO;
                }
            }
    }
    cout << ((LL)f[n-1][0]+f[n-1][1])%MO << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}