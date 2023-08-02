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

int n1, n2, m, res = 1e9;
vector<int> e[N];
int dep1[N], dep2[N];

int bfs1(int root) {
    queue<int> q;
    q.push(root);
    dep1[root] = 1;
    int mx = 1;
    while(q.size()) {
        auto u = q.front();
        q.pop();
        for(auto v : e[u]) {
            if(v <= n1 && !dep1[v]) {
                dep1[v] = dep1[u] + 1;
                mx = max(mx, dep1[v]);
                q.push(v);
            }
        }
    }
    return mx;
}
int bfs2(int root) {
    queue<int> q;
    q.push(root);
    dep2[root] = 1;
    int mx = 1;
    while(q.size()) {
        auto u = q.front();
        q.pop();
        for(auto v : e[u]) {
            if(v > n1 && !dep2[v]) {
                dep2[v] = dep2[u] + 1;
                mx = max(mx, dep2[v]);
                q.push(v);
            }
            if(v <= n1) {
                res = min(res, dep1[v] + dep2[u] - 1);
            }
        }
    }
    return mx;
}
void solve() {
    cin >> n1 >> n2 >> m;
    while(m --) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b), e[b].push_back(a);
    }
    int ans = bfs1(1) + bfs2(n1+n2) - 1;
    ans = min(ans, res);
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