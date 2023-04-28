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
int n, m;
LL a[N];
LL fa[N], s[N], siz[N];
set<PII> son[N];

void dfs(int u, int f) {
    fa[u] = f, siz[u] = 1, s[u] = a[u];
    for(int v : e[u]) {
        if(v != f) {
            dfs(v, u);
            son[u].emplace(-siz[v], v);
            siz[u] += siz[v];
            s[u] += s[v];
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b), e[b].push_back(a);
    }
    dfs(1, 0);
    while(m --) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            cout << s[x] << '\n';
        }
        else {
            if(son[x].empty()) continue;

            int t = son[x].begin()->se;
            // siz[x], siz[t] recognize
            son[fa[x]].erase({-siz[x], x});
            son[x].erase({-siz[t], t});

            siz[x] -= siz[t];
            siz[t] += siz[x];
            s[x] -= s[t];
            s[t] += s[x];
            
            son[fa[x]].emplace(-siz[t], t);
            son[t].emplace(-siz[x], x);

            fa[t] = fa[x];
            fa[x] = t;
        }
    }
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