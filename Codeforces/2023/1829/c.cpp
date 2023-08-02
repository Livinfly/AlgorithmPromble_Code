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
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        string s; cin >> s;
        if(mp.count(s)) mp[s] = min(mp[s], x);
        else mp[s] = x;
    }
    int ans = 1e9;
    if(mp.count("11")) {
        ans = min(ans, mp["11"]);
    }
    if(mp.count("10") && mp.count("01")) {
        ans = min(ans, mp["10"] + mp["01"]);
    }
    if(ans == (int)1e9) ans = -1;
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}