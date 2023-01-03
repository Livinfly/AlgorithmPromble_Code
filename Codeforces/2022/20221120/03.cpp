#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = N*N;

int idx, h[N], ne[M], ver[M];
int n;
int indeg[N];
char g[N][N];
bool st[N][N];
vector<int> res[N];

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void bfs() {
    queue<int> q;
    int usem = 0;
    for(int i = 1; i <= n; i ++) {
        res[i].emplace_back(i);
        st[i][i] = true;
        if(!indeg[i]) 
            q.push(i);
    }
    while(q.size()) {
        int t = q.front(); q.pop();
        for(int i = h[t]; ~i; i = ne[i]) {
            int v = ver[i];
            for(auto x : res[t]) {
                if(!st[v][x]) {
                    res[v].emplace_back(x);
                    st[v][x] = true;
                }
            }
            if(--indeg[v] == 0) {
                q.push(v);
            }
        }
    }
}
void solve() {
    idx = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        h[i] = -1, indeg[i] = 0;
        res[i].clear();
    }
    memset(st, 0, sizeof st);
    for(int i = 1; i <= n; i ++) cin >> g[i]+1;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++) 
            if(g[i][j] == '1') add(i, j), indeg[j] ++;
    bfs();
    for(int i = 1; i <= n; i ++) {
        // sort(all(res[i]));
        cout << res[i].size();
        for(auto x : res[i])
            cout << ' ' << x;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}