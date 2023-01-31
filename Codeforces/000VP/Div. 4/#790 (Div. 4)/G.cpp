#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4010;

int idx, h[N], ne[N], ver[N];
int n, res;
int cntW[N], cntB[N];
string s;

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u) {
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = ver[i];
        dfs(v);
        cntB[u] += cntB[v];
        cntW[u] += cntW[v];
    }
    if(cntB[u] == cntW[u]) res ++;
}
void solve() {
    idx = res = 0;
    memset(h, -1, sizeof h);
    memset(cntB, 0, sizeof cntB);
    memset(cntW, 0, sizeof cntW);
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        int a;
        cin >> a;
        add(a, i);
    }
    cin >> s;
    s = " "+s;
    for(int i = 1; i <= n; i ++)
        if(s[i] == 'B') cntB[i] = 1;
        else cntW[i] = 1;
    dfs(1);
    cout << res << '\n';
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