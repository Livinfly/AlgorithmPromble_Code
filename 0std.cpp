#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

const int N = 110;

int n, m, f, p;
PII prov;
int g[N][N], tranf[N][N];
vector<PIII> cons;
bool st[4];

void solve() {
    cin >> n >> m >> f >> p;
    cin >> prov.fi >> prov.se;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> g[i][j];
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        cons.push_back({{a, b}, c});
    }
    for(int i = 0; i < f; i ++) 
        for(int j = 0; j < f; j ++)
            cin >> tranf[i][j];
    vector<int> ans;
    for(int i = 0; i < m; i ++) {
        if(cons[i].fi.fi == prov.fi && cons[i].fi.se < prov.se && !st[0]) {
            ans.push_back(i);
            st[0] = true;
        }
        else if(cons[i].fi.fi == prov.fi && cons[i].fi.se > prov.se && !st[1]) {
            ans.push_back(i);
            st[1] = true;
        }
        else if(cons[i].fi.se == prov.se && cons[i].fi.fi > prov.se && !st[2]) {
            ans.push_back(i);
            st[2] = true;
        }
        else if(cons[i].fi.se == prov.se && cons[i].fi.fi < prov.se && !st[3]) {
            ans.push_back(i);
            st[3] = true;
        }
    }
    cout << 0 << '\n';
    cout << prov.fi << ' ' << prov.se << ' ' << ans.size() << ' ';
    for(int i = 0; i < ans.size(); i ++)
        cout << 1 << ' ' << ans[i]+1 << ' ' << cons[ans[i]].se << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}