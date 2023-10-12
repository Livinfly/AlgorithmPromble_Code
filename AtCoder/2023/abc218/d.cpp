// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    int n; cin >> n;
    vector<PII> ve(n);
    for(auto &[x, y]: ve) cin >> x >> y;
    set<PII> st;
    for(auto p: ve) st.insert(p); 
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = i+1; j < n; j ++) {
            auto [a0, b0] = ve[i];
            auto [a1, b1] = ve[j];
            if(a0 == a1 || b0 == b1) continue;
            if(st.count({a0, b1}) && st.count({a1, b0})) ans++;
        }
    }
    cout << ans/2 << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}