#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1510;

vector<int> e[N];
int dep[N];
int n, m;

void bfs() {
    dep[1] = 1;
    queue<int> q;
    q.push(1);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v : e[u]) {
            if(!dep[v]) {
                dep[v] = dep[u]+1;
                q.push(v);
            }
        }
    }
}
void solve() {
    for(int i = 1; i <= n; i ++) dep[i] = 0, e[i].clear();
    cin >> n >> m;
    while(m --) {
        int a, b;
        cin >> a >> b;
        e[b].push_back(a);
    }
    bfs();
    vector<vector<int>> group(n+1);
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        if(!dep[i]) {
            cout << "INFINITE\n";
            return;
        }
        group[dep[i]].push_back(i);
        mx = max(mx, dep[i]);
    }

    cout << "FINITE\n";
    vector<int> ans;
    for(int i = 0; i < mx; i ++) {
        for(int j = i; j >= 0; j --) {
            for(auto x : group[mx-j])
                ans.push_back(x);
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i ++) 
        cout << ans[i] << " \n"[i == ans.size()-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}