#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10, M = 2e5+10;

int idx, h[N], ne[M], ver[M];
int son[N], siz[N];
int n, cnt[25];
PII p[N];

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs1(int u, int fa) {
    siz[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = ver[i];
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int fa, int line) {
    p[u] = {++ cnt[line], line};
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = ver[i];
        if(v != fa && v != son[u])
            dfs2(v, u, line+1);
    }
    if(son[u]) 
        dfs2(son[u], u, line);
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs1(1, -1);
    dfs2(1, -1, 1);
    for(int i = 1; i <= n; i ++)
        cout << p[i].fi << ' ' << p[i].se << '\n';
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
/*
轻重链剖分
    先把轻儿子放在下一行，再把重儿子放在父节点这一行的右边

    能够不挺分下去的儿子最多只有log n层，且列不会超出，符合
*/