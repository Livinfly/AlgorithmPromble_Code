#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

char g[2][N];

void solve() {
    int n = 2, m;
    cin >> m;
    for(int i = 0; i < 2; i ++)
        cin >> g[i];
    int x = -1, y = -1;
    for(int i = 0; i < m; i ++) {
        if(g[0][i] != g[1][i]) {
            x = (g[1][i] == 'B');
            y = i;
            break;
        }
    }
    if(!~x && !~y) {
        cout << "YES\n";
        return;
    }
    for(int i = y; i < m-1; i ++) {
        if(g[x^1][i] == 'B') {
            x ^= 1;
        }
        if(g[x][i+1] != 'B') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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