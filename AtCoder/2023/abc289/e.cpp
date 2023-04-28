#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, M = 4010;

struct rec {
    int a, b;
    int cnt;
};

int idx, h[N], ne[M], ver[M];
int n, m;
int c[N];
bool vis[N*N+N];

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int bfs() {
    queue<rec> q;
    q.push({1, n, 0});
    vis[1*N+n] = true;
    while(q.size()) {
        auto t = q.front(); q.pop();
        for(int i = h[t.a]; ~i; i = ne[i]) {
            int va = ver[i];
            for(int j = h[t.b]; ~j; j = ne[j]) {
                int vb = ver[j];
                if(c[va] != c[vb] && !vis[va*N+vb]) {
                    if(va == n && vb == 1) {
                        return t.cnt+1;
                    }
                    q.push({va, vb, t.cnt+1});
                    vis[va*N+vb] = true;
                }
            }
        }
    }
    return -1;
}
void solve() {
    idx = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        h[i] = -1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            vis[i*N+j] = false;
    for(int i = 1; i <= n; i ++) 
        cin >> c[i];
    while(m --) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    cout << bfs() << '\n';
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