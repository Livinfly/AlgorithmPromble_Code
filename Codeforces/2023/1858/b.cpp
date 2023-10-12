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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> s(m+2); s[0] = 1, s[m+1] = n-d+1;
    for(int i = 1; i <= m; i ++) cin >> s[i];
    int ans = 1;
    for(int i = 1; i <= m+1; i ++) {
        // cerr << (s[i]-s[i-1]+d-1) / d << '\n';
        ans += (s[i]-s[i-1]+d-1) / d;
    }
    // ans -= (n-s[m] < n);
    int mx = -1, cnt = -1;
    for(int i = 1; i <= m; i ++) {
        int t = (s[i]-s[i-1]+d-1)/d + (s[i+1]-s[i]+d-1)/d 
                - (s[i+1]-s[i-1]+d-1)/d;
        // cerr << "?" << i << ' ' << t << '\n';
        if(t > mx) mx = t, cnt = 1;
        else if(t == mx) cnt++;
    }
    // cerr << mx << '\n';
    cout << ans-mx << ' ' << cnt << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}