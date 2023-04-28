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
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int cnt = 1, res = 1;
    int r1 = a[0]+w;
    for(int i = 1; i < a.size(); i ++) {
        if(cnt < k && a[i] <= r1+d) {
            cnt ++;
        }
        else {
            r1 = a[i]+w;
            cnt = 1;
            res ++;
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
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}