#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, MO = 1e9+7;

int qpm(int a, int b, const int &c = MO) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = 1LL*ans*a%MO;
        a = 1LL*a*a%MO;
        b >>= 1;
    }
    return ans;
}

int n, k, ans;
vector<int> e[N];
int f[N], siz[N];

void dfs1(int u, int fa) {
    siz[u] = 1;
    for(auto v : e[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        f[u] = (1LL*f[u] + f[v]) % MO;
    }
    f[u] = (1LL*f[u] + siz[u]-1) % MO;
}
void dfs2(int u, int fa) {
    for(auto v : e[u]) {
        if(v == fa) continue;
        f[v] = (((1LL*f[v] + (f[u]-f[v]-siz[v]) % MO) % MO) + n-siz[v]) % MO;
        dfs2(v, u);
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    if(k & 1) {
        cout << "1\n";
    }
    else {
        dfs1(1, -1);
        dfs2(1, -1);
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            ans = ((1LL*ans + f[i])%MO+n-1) % MO;
        }
        cout << 1LL*ans * qpm(n, MO-2) % MO * qpm(n-1, MO-2) % MO << '\n';
    }
}
// 20/12

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