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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int hh = 0, tt = 0, tsum = 0, res = -1;
    while(tt < n) {
        tsum += a[tt ++];
        if(tsum < m) ;
        else if(tsum == m) {
            if(!~res) res = n-(tt-hh);
            else res = min(res, n-(tt-hh));
        }
        else tsum -= a[hh ++];
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