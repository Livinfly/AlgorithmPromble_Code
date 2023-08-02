// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1), s(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] &= 1;
        s[i] = s[i-1] + a[i];
    }
    while(q --) {
        int l, r, k;
        cin >> l >> r >> k;
        k &= 1;
        if((s[r] - s[l-1] & 1)  == (((r-l+1) * k) & 1)) {
            if(s[n] & 1) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        } 
        else {
            if(s[n] & 1) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}