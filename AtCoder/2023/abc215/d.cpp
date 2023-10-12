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

vector<bool> vis;

vector<int> PrimeFactor(int x) {
    vector<int> ret;
    for(int i = 2; i <= x/i; i ++) {
        if(x % i == 0) {
            while(x % i == 0) x /= i;
            ret.push_back(i);
        }
    }
    if(x > 1) ret.push_back(x);
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vis.resize(m+1);
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        auto divs = PrimeFactor(x);
        for(auto x: divs) {
            if(vis[x]) continue;
            for(int y = x; y <= m; y += x) {
                vis[y] = true;
            }
        }
    }
    vector<int> ans;
    for(int i = 1; i <= m; i ++) {
        if(!vis[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}