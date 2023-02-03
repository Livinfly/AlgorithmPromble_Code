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

int n;
LL sum;
LL a[N][N], g[N][N], ud[N][N], lr[N][N], row[N], col[N]; // u-d, l-r

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> g[i][j];
            // for(int k = 1; k <= n; k ++)
            //     g[i][j] += (abs(i-k)+abs(j-k))*k;
    // for(int i = 1; i <= n; i ++)
    //     for(int j = 1; j <= n; j ++)
    //         cout << g[i][j] << " \n"[j == n];
    for(int i = 1; i < n; i ++)
        for(int j = 1; j < n; j ++) {
            ud[i][j] = g[i+1][j]-g[i][j];
            lr[i][j] = g[i][j+1]-g[i][j];
        }
    row[1] = (ud[1][1]+ud[n-1][1])/2;
    col[1] = (lr[1][1]+lr[1][n-1])/2;
    LL D = (ud[1][1]+lr[1][1])/2;
    for(int i = 2; i < n; i ++)
        row[i] = (ud[i][1]-ud[i-1][1])/2;
    for(int j = 2; j < n; j ++)
        col[j] = (lr[1][j]-lr[1][j-1])/2;

    // cout << "--------\n";
    // for(int j = 2; j < n; j ++)
    //     cout << col[j] << ' ';
    // cout << '\n';
    // cout << "--------\n";
    // for(int i = 2; i < n; i ++)
    //     cout << row[i] << '\n';
    // cout << "--------\n";
    // for(int i = 1; i < n; i ++)
    //     for(int j = 1; j <= n; j ++)
    //         cout << ud[i][j] << " \n"[j == n];
    // cout << "--------\n";
    // for(int i = 1; i <= n; i ++)
    //     for(int j = 1; j < n; j ++)
    //         cout << lr[i][j] << " \n"[j == n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    solve();
    return 0;
}