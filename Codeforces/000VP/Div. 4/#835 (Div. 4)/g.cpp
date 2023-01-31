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

int idx, h[N], ne[N<<1], ver[N<<1], e[N<<1];
int n, a, b;
int f[N];
set<int> st;

void add(int a, int b, int c) {
    ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int fa, int no) {
    if(u != b)
        st.insert(f[u]);
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = ver[i];
        if(v == fa || v == no) continue;
        f[v] = f[u]^e[i];
        dfs(v, u, no);
    }
}
void solve() {
    cin >> n >> a >> b;
    idx = 0;
    for(int i = 1; i <= n; i ++) h[i] = -1;

    for(int i = 0; i < n-1; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    f[a] = 0;
    st.clear();
    dfs(a, -1, b);
    auto st0 = st;

    st.clear();
    f[b] = 0;
    dfs(b, -1, -1);
    for(auto x : st) {
        if(st0.count(x)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}
/*
a -> c ---> d -> b
 不经过b
*/