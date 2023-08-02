#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 4>> e(m);
    vector<map<int, int>> bus(n);
    for(int i = 0; i < m; i ++) {
        auto &[a, b, s, t] = e[i];
        cin >> a >> b >> s >> t;
        a--, b--;
        bus[a][s] = i;
    }
    auto FindBus = [&](int u, int t) {
        auto it = bus[u].lower_bound(t);
        if(it == bus[u].end()) return -1;
        return it->se;
    };
    vector<vector<int>> f(m, vector<int>(21, -1));
    for(int i = 0; i < m; i ++) {
        f[i][0] = FindBus(e[i][1], e[i][3]);
    }
    for(int k = 1; k <= 20; k ++) {
        for(int i = 0; i < m; i ++) {
            if(f[i][k-1] != -1) {
                f[i][k] = f[f[i][k-1]][k-1];
            }
        }
    }
    while(q --) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        int nbus = FindBus(y, x);
        if(nbus == -1) {
            cout << y+1 << '\n';
            continue;
        }
        for(int k = 20; k >= 0; k --) {
            if(f[nbus][k] != -1 && e[f[nbus][k]][2] < z) {
                nbus = f[nbus][k];
            }
        }
        if(z <= e[nbus][2]) cout << e[nbus][0]+1 << '\n';
        else if(e[nbus][3] < z) cout << e[nbus][1]+1 << '\n';
        else cout << e[nbus][0]+1 << ' ' << e[nbus][1]+1 << '\n';
    }
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