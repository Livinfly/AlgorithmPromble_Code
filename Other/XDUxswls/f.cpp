#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct Rec {
    LL time;
    int id;
    bool operator < (const Rec &o) const {
        return time < o.time;
    }
} t[N][N];

LL n, res = INF;
int gid[N], cnt1[N];
bool vis[N];

bool cmp(int a, int b) {
    return cnt1[a] < cnt1[b];
}
void dfs(int g, LL tres) {
    // cout << g << ' ' << tres << ' ' << res << '\n';
    if(tres >= res) return;
    if(g == n) {
        res = tres;
        return;
    }
    for(int i = 0; i < n; i ++) {
        auto tt = t[g][i];
        if(tt.time == INF) break;
        if(!vis[tt.id]) {
            vis[tt.id] = true;
            dfs(g+1, max(tres, tt.time));
            vis[tt.id] = false;
        }
    }
}
void solve() {
    cin >> n;
    iota(gid, gid+n, 0);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> t[i][j].time;
            t[i][j].id = j;
            if(t[i][j].time != 0) 
                cnt1[i] ++;
            else 
                t[i][j].time = INF;
        }
        sort(t[i], t[i]+n);
    }
    sort(gid, gid+n, cmp);
    dfs(0, 0);
    cout << (res == INF ? -1 : res) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("o.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}