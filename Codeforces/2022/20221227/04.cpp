#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int h[N], s[N];

int GetPos(const int &x, const int &y) {
    return (x-1)*m+y;
}
bool ok(int mid) {
    int good = mid*mid;
    for(int i = 1; i <= n*m; i ++)
        s[i] = 0;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= m; j ++) {
            int ij = GetPos(i, j);
            if(h[ij] >= mid) s[ij] = 1;
            // cout << h[ij] << ' ' << mid << ' ' << s[ij] << '\n';
            s[ij] += s[GetPos(i, j-1)]+s[GetPos(i-1, j)]-s[GetPos(i-1,j-1)];
        }
    for(int i = mid; i <= n; i ++)
        for(int j = mid; j <= m; j ++) {
            int cnt = s[GetPos(i, j)]-s[GetPos(i-mid, j)]-s[GetPos(i, j-mid)]+s[GetPos(i-mid, j-mid)];
            if(cnt >= good) return true;
        }
    return false;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> h[GetPos(i, j)];
    int l = 1, r = min(n, m);
    while(l < r) {
        int mid = l+r+1>>1;
        if(ok(mid)) l = mid;
        else r = mid-1;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}