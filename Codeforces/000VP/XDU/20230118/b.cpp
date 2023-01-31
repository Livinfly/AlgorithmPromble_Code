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

char g[N][N];

void solve() {
    int n, k;
    cin >> n >> k;
    if(k > n*n-n || n == 2 && k >= 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(i == j || cnt >= k) g[i][j] = '.';
                else g[i][j] = '#', cnt ++;
            }
        }
        swap(g[1][1], g[1][n]), swap(g[n][1], g[n][n]);
        for(int i = 1; i <= n; i ++)
            cout << g[i]+1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}