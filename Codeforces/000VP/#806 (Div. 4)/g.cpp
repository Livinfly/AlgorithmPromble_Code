#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;

LL n, k;
LL a[N], f[N][31];

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
        
    LL res = 0;
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++)
        for(int bit = 0; bit < 31; bit ++) {
            f[i][bit] = f[i-1][bit]-k+(a[i]>>bit);
            if(bit > 0) 
                f[i][bit] = f[i-1][bit-1]+(a[i]>>bit);
            // cout << i << ' ' << bit << ' ' << f[i][bit] << '\n';
            if(bit == 30) 
                res = max(res, f[i][bit]);
        }
    for(int bit = 0; bit < 31; bit ++)
        res = max(res, f[n][bit]);
    cout << res << '\n';
    // cout << "-------------\n";
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