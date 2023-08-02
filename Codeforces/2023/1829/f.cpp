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

// x*y, y
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> e(n);
    while(m --) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back(v), e[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    int cnt = 0;
    for(auto x: deg) cnt += (x == 1);
    int x, y;
    for(int i = 0; i < n; i ++) {
        if(deg[i] == 1) {
            int t = e[i].back();
            y = e[t].size()-1;
            break;
        }
    }
    x = cnt/y;
    cout << x << ' ' << y << '\n';
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