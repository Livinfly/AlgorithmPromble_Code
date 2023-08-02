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
    string s;
    cin >> s;
    int n = s.size();
    LL N;
    cin >> N;
    LL ans = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            ans += 1LL << (n-i-1);
        }
    }
    if(ans > N) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < n; i ++) {
        if(s[i] == '?' && ans + (1LL << (n-i-1)) <= N) {
            ans += 1LL << (n-i-1);
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