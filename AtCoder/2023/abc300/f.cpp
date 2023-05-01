#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<LL> p;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'x') {
            p.push_back(i);
        }
    }
    LL cnt = p.size(), x = m*cnt;
    if(k == x) {
        cout << m*n << '\n';
        return;
    }
    LL res = k/cnt*n + max(p[k%cnt], n-p[cnt-k%cnt-1]-1);
    // cout << k << '\n';
    // cout << p[k]+1-1 << ' ' << n-p[nn-k-1]-1 << '\n';
    for(int i = 0; i < cnt; i ++) {
        if(i+k+1 < x) {
            res = max(res, p[(i+k+1)%cnt]+n*((i+k+1)/cnt)-p[i]-1);
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
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}