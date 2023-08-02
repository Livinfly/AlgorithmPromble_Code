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
    int n, m, tot;
    cin >> n >> m;
    tot = (1 << n) - 1;
    vector<string> a(n);
    for(auto &x : a) cin >> x;
    auto diff = [&](string a, string b) {
        int ret = 0;
        for(int i = 0; i < m; i ++) {
            if(a[i] != b[i]) ret ++;
        }
        // cerr << a << ' ' << b << ' ' << ret << '\n';
        return ret;
    };
    function<bool(int, string)> dfs = [&](int status, string s) {
        // cout << status << ' ' << s << '\n';
        if(status == tot) return true;
        for(int i = 0; i < n; i ++) {
            if(!(status >> i & 1) && (s == "" || diff(s, a[i]) == 1)) {
                if(dfs(status | 1 << i, a[i])) {
                    return true;
                }
            }
        }

        return false;
    };
    cout << (dfs(0, "") ? "Yes" : "No") << '\n';
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