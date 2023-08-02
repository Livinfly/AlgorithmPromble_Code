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
    cin >> n;
    vector<int> a(n);
    vector<array<LL, 3>> cnt(2);
    for(auto &x : a) cin >> x;
    string s;
    cin >> s;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'X') cnt[1][a[i]] ++;
    }
    LL ans = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'E') {
            if(a[i] == 0) {
                ans += (cnt[0][0]+cnt[0][2]) * (cnt[1][0]+cnt[1][2]) * 1;
                ans += (cnt[0][0]*cnt[1][1] + cnt[0][1]*cnt[1][0] + cnt[0][1]*cnt[1][1]) * 2;
                ans += (cnt[0][1]*cnt[1][2] + cnt[0][2]*cnt[1][1]) * 3;
            }
            else if(a[i] == 1) {
                ans += (cnt[0][0]*cnt[1][0] + cnt[0][0]*cnt[1][1] + cnt[0][1]*cnt[1][0]) * 2;
                ans += (cnt[0][0]*cnt[1][2] + cnt[0][2]*cnt[1][0]) * 3;
            }
            else {
                ans += (cnt[0][0]*cnt[1][0] + cnt[0][0]*cnt[1][2] + cnt[0][2]*cnt[1][0]) * 1;
                ans += (cnt[0][0]*cnt[1][1] + cnt[0][1]*cnt[1][0]) * 3;
            }
        }
        else if(s[i] == 'M') {
            cnt[0][a[i]] ++;
        }
        else {
            cnt[1][a[i]] --;
        }
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