#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5010;

int dxy[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};
int n, ti, res = -1;
PII p[N];

bool smove(int opt) {
    int nx = p[0].fi+dxy[opt][0], ny = p[0].se+dxy[opt][1];
    PII np = mkp(nx, ny);
    for(int i  = n-1; i > 0; i --) {
        p[i] = p[i-1];
        if(p[i] == np)
            return true; 
    }
    p[0] = np;
    return false;
}
void solve() {
    cin >> n >> ti;
    for(int i = 0; i < n; i ++) cin >> p[i].fi >> p[i].se;
    for(int i = 0; i < ti; i ++) {
        int opt;
        cin >> opt;
        bool flag = smove(opt);
        if(res == -1 && flag) {
            res = i;
        }
    }
    if(res == -1) res = ti;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    solve();
    return 0;
}