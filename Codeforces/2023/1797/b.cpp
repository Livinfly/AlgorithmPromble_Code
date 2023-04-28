#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e3+10;

int n, k;
int g[N][N];

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> g[i][j];
    int cnt = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) 
            cnt += g[i][j] != g[n-i-1][n-j-1];
    cnt /= 2;
    if(cnt > k || n%2 == 0 && (k-cnt)%2)
        cout << "NO\n";
    else 
        cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}