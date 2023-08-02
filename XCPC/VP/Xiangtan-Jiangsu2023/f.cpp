#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int A, B, P, Q;
map<int, double> dp;

double dfs(int x) {
    if(dp.count(x)) return dp[x];
    double ret = 0;
    // cout << x << ' ' << ret << '\n';
    if(x >= B) {
        if(B > 1) {
            ret = max(1 + 1.*P / 100. + dfs(x-B), 1 +  Q * dfs(x-B+1) / 100. + (100-Q) * dfs(x-B) / 100.);
        }
        else {  
            ret = max(1 + 1.*P / 100. + dfs(x-B), 100./(100. - Q) + dfs(x-B));
        }
    }
    return dp[x] = ret;
}
void solve() {
    cin >> A >> B >> P >> Q;
    cout << dfs(A) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20); // double
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