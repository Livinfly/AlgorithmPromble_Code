// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 310, INF = 0x3f3f3f3f;

int n, X, Y;
int dp[N][N];

void solve() {
    cin >> n >> X >> Y;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        for(int i = X; i >= 0; i--) {
            for(int j = Y; j >= 0; j--) {
                int a = min(i+x, X), b = min(j+y, Y);
                dp[a][b] = min(dp[a][b], dp[i][j]+1);
            }
        }
    }
    cout << (dp[X][Y]==INF ? -1 : dp[X][Y]) << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}