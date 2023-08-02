#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5+10;

int ans;
vector<int> e[N];
int tag[N];

void dfs(int u) {
    if(tag[u] >= 0) {
        ans ++;
    }
    for(auto v : e[u]) {
        tag[v] = max(tag[v], tag[u]-1);
        dfs(v);
    }
}
void solve() {
    memset(tag, -1, sizeof tag);
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    p[1] = 0;
    for(int i = 2; i <= n; i ++) cin >> p[i];
    while(m --) {
        int a, b;
        cin >> a >> b;
        tag[a] = max(tag[a], b);
    }
    for(int i = 2; i <= n; i ++) {
        e[p[i]].push_back(i);
    }
    dfs(1);
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
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}