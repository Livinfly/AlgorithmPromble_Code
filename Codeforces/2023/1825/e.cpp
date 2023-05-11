#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;

vector<int> e[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b), e[b].push_back(a);
    }
    vector<map<int, int>> f(n+1);
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
        int mx = 1, cnt = 0;
        for(auto v : e[u]) {
            if(v == fa) continue;
            a[v] ^= a[u], cnt ++;
            dfs(v, u);
            if(f[u].size() < f[v].size()) swap(f[u], f[v]);
            for(auto [x, c] : f[v]) {
                f[u][x] += c;
                mx = max(mx, f[u][x]);
            }
        }
        if(!cnt) f[u][a[u]] = 1;
        else ans += cnt-mx;
        if(mx != 1) {
            for(auto iter = f[u].begin(); iter != f[u].end(); ) {
                if(iter->se == mx) {
                    iter->se = 1, iter ++;
                }
                else {
                    iter = f[u].erase(iter);
                }
            }
        }
    };
    dfs(1, -1);
    cout << ans+(!f[1].count(0)) << '\n';
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