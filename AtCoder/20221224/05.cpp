#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int dxy[4][2] = {
    {0, 1}, 
    {1, 0}, 
    {0, -1},
    {-1, 0},
};
int n, m;
int g[1010][1010];

bool check(int x, int y) {
    for(int i = 0; i < 4; i ++) {
        int a = x + dxy[i][0], b = y + dxy[i][1];
        if(a < 0 || b < 0 ||
            a >= n || b >= m ||
            g[x][y] != g[a][b]) continue;
        return true;
    }
    return false;
}
bool check1(int i) {
    int cnt = 1;
    for(int j = 0; j < m; j ++) {
        if(!check(i, j)) return false;
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) 
        for(int j = 0; j < m; j ++)
            cin >> g[i][j];
    int cnt = 0;
    for(int i = 0; i < n-1; i ++) {
        if(!check1(i)) {
            for(int j = 0; j < m; j ++)
                g[i+1][j] ^= 1;
            cnt ++;
        }
    }
    
    for(int i = 0; i < n; i ++) {
        if(!check1(i)) {
            cout << "-1\n";
            return;
        }
    }
    
    cout << min(n-cnt, cnt) << '\n';
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