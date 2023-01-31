#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5+10;

int idx, h[N], ne[N<<1], ver[N<<1];
int n;
int p, res;
int d[N];

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u) {
    if(res < d[u]) {
        p = u, res = d[u];
    }
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = ver[i];
        if(!~d[v]) {
            d[v] = d[u]+1;
            dfs(v);
        }
    }
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    memset(d, -1, sizeof d);
    d[1] = 0;
    dfs(1);
    res = 0;

    memset(d, -1, sizeof d);
    d[p] = 0;
    dfs(p);
    if(res == 1) {
        cout << "0\n";
        return;
    }
    for(int i = 1; ; i ++) {
        if(res <= (1<<i) && res > (1<<(i-1))) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}