#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, M = 4e6+10;

int idx, h[N], ne[M], ver[M];
int n, m, res;
bool vis[N];

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u) {
    res ++;
    if(res == (int)1e6) {
        cout << res << '\n';
        exit(0);
    }
    vis[u] = true;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = ver[i];
        if(!vis[v]) 
            dfs(v);
    }
    vis[u] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << res << '\n';
    return 0;
}