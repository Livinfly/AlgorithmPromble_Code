// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 2e3+10, M = 1e6+10;

int pos[N];
LL s[N][N];

void solve() {
    int n;
    cin >> n;
    int x = lower_bound(pos, pos+2000, n) - pos, y = n - pos[x-1] - 1;
    // cerr << x << ' ' << y << '\n';
    LL ans = 0;
    // cerr << n << '\n';
    for(int i = x; i >= 0; i --) {
        int l = y - (x-i), r = y;
        // cerr << l << ' ' << r << '\n';
        ans += s[i][r] - (l > 0 ? s[i][l-1] : 0);
        // cerr << s[i][r] - (l > 0 ? s[i][l-1] : 0) << '\n';
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    LL t = 1;
    for(int i = 0; i < 2000; i ++) {
        for(int j = 0; j <= i; j ++) {
            if(j > 0) s[i][j] = s[i][j-1];
            s[i][j] += t*t;
            t++;
        }
        for(int j = i+1; j < 2000; j ++) {
            s[i][j] = s[i][j-1];
        }
    }
    // for(int i = 0; i < 5; i ++) {
    //     cerr << s[i][0] << ' ';
    //     for(int j = 1; j < 5; j ++) {
    //         cerr << s[i][j] - s[i][j-1] << ' ';
    //     }
    //     cerr << '\n';
    // }
    for(int i = 0; i < 2000; i ++) {
        pos[i] = (i+1) * (i+2) / 2;
    }
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}