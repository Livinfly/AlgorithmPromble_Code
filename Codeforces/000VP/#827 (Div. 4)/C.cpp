#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

char g[10][10];

void solve() {
    int n = 8;
    for(int i = 0; i < n; i ++) cin >> g[i];
    for(int i = 0; i < n; i ++) {
        char t = 'R';
        int j;
        for(j = 0; j < n; j ++)
            if(g[i][j] != t) break;
        if(j == n) {
            cout << t << '\n';
            return;
        }
    }
    for(int i = 0; i < n; i ++) {
        char t = 'B';
        int j;
        for(j = 0; j < n; j ++)
            if(g[j][i] != t) break;
        if(j == n) {
            cout << t << '\n';
            return;
        }
    }
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