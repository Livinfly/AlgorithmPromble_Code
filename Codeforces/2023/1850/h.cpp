#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

vector<PII> e[N];
map<LL, LL> mp;

bool dfs(int u) {
    for(auto [v, c]: e[u]) {
        if(!mp.count(v)) {
            mp[v] = mp[u]+c;
            if(!dfs(v)) {
                return false;
            }
        }
        else if(mp[v] != mp[u]+c) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        e[i].clear();
    }
    mp.clear();
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c}), e[b].push_back({a, -c});
    }
    for(int i = 1; i <= n; i ++) {
        if(!mp.count(i)) {
            mp[i] = 0;
            if(!dfs(i)) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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