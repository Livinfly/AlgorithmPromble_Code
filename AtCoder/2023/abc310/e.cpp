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
    int n;
    string s;
    cin >> n >> s;
    LL ans = 0;
    array<LL, 2> cnt{};
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            cnt[1] = cnt[0] + cnt[1];
            cnt[0] = 1;
        }
        else {
            swap(cnt[0], cnt[1]);
            cnt[1] ++;
        }
        ans += cnt[1];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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