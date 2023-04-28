#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int a[2][100010];

void solve() {
    int n;
    cin >> n;
    int x = 1, y = n+1;
    a[0][0] = 2*n, a[1][n-1] = 2*n-1;
    for(int i = 0; i < n-1; i ++)
        if(i & 1) a[1][i] = y ++, a[0][i+1] = y ++;
        else a[1][i] = x ++, a[0][i+1] = x ++;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < n; j ++)
            cout << a[i][j] << " \n"[j == n-1];
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