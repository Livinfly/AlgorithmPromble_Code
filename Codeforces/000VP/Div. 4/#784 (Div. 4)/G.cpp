#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

string s[50];
void work(int x, int y) {
    if(x < 0) return;
    int cnt = 0;
    int L = x;
    while(x >= 0) {
        if(s[x][y] == 'o') break;
        else if(s[x][y] == '*') cnt ++;
        x --;
    }
    // cout << x << ':' << cnt << '\n';
    for(int i = L; i > x; i --)  {
        // cout << i-L << ":::" << cnt << '\n';
        if(L-i < cnt) s[i][y] = '*';
        else s[i][y] = '.';
    }
    work(x-1, y);
};
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> s[i];
    for(int i = 0; i < m; i ++) {
        work(n-1, i);
    }
    for(int i = 0; i < n; i ++) cout << s[i] << '\n';
    cout << '\n';
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