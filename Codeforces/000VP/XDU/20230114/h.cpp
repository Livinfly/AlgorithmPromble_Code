#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int P = 1e9+7;

LL n, res = 1;

void solve() {
    cin >> n;
    vector<LL> a(n);
    for(auto &x : a) cin >> x;
    LL p = 0;
    for(int i = 0; i < n; i ++) {
        if(a[p] < a[i]) {
            res = res*(i-p+1)%P;
            p = i;
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
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
