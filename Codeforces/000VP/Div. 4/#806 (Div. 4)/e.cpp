#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int n;
char g[N][N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> g[i]+1;
    int m = n/2;
    int res = 0;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= m; j ++) {
            vector<int> cnt(2);
            cnt[g[i][j]-'0'] ++;
            cnt[g[j][n-i+1]-'0'] ++;
            cnt[g[n-i+1][n-j+1]-'0'] ++;
            cnt[g[n-j+1][i]-'0'] ++;
            res += min(cnt[0], cnt[1]);
        }
    if(n & 1) {
        int p = m+1;
        for(int i = 1; i <= m; i ++) {
            vector<int> cnt(2);
            cnt[g[p][p+i]-'0'] ++;
            cnt[g[p+i][p]-'0'] ++;
            cnt[g[p][p-i]-'0'] ++;
            cnt[g[p-i][p]-'0'] ++;
            res += min(cnt[0], cnt[1]);
        }
    }
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
/*

01010
10101
01010
10101
01010

2
*/