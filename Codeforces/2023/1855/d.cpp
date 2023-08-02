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

// f[i, j] 考虑了前 i 位，解锁了前 j 位的最小代价。
// f[i, j] = min(f[i-1, j], f[i-1, j-a[i]] + a[i]);    O(n^2)
// 
void solve() {
    const LL INF = 1e18;
    int n; cin >> n;
    vector<int> a(n+1);
    vector<LL> s(n+1);
    vector<vector<LL>> f(n+1, vector<LL>(n+1, INF));
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    f[0][1] = 0;
    LL ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i-1; j <= n; j ++) {
            f[i][j] = f[i-1][j];
            if(j >= a[i]) {
                f[i][j] = min(f[i][j], f[i-1][j-a[i]] + a[i]);
            }
            ans = max(ans, s[j] - f[i][j]);
        }
    }
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= n; j ++) {
    //         cout << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';
    //     }
    // }
    cout << ans << '\n';
}
// f[i] 表示 i 位是否恰好解锁到。
// 由于观察到恰好解锁到，他的答案一定是 s[i] - (i-1)。
// 恰好解锁到的位的答案一定优于或等价于，不恰好解锁到的。
void solve1() {
    const int N = 2e5+10;
    int n; cin >> n;
    vector<int> a(n+1);
    vector<LL> s(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    LL ans = 0;
    bitset<N> f{};
    f[1] = 1;
    for(int i = 1; i <= n; i ++) {
        f |= f<<a[i]; // 恰好能到 i 位的已经更新出去了
        if(f[i]) {
            f[i] = 0; // 之后的不能恰好到比自己小的位置来转移。
            ans = max(ans, s[i] - (i-1));
        }
    }
    for(int i = n; i <= n*2; i ++) {
        if(f[i]) {
            ans = max(ans, s[n] - (i-1));
        }
    }
    cout << ans << '\n';
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
        solve1();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}