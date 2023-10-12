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
    int n; cin >> n;
    vector<bool> vis(n);
    int cnt = 0;
    vector<int> t(n), ans(n);
    set<PII> st;
    for(auto &x: t) cin >> x;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        st.insert({x, i});
    } 
    while(st.size()) {
        auto [val, id] = *st.begin();
        st.erase(st.begin());
        if(vis[id]) continue;
        ans[id] = val;
        vis[id] = true;
        cnt++;
        if(cnt == n) break;
        st.insert({val+t[id], (id+1)%n});
    }
    for(auto x: ans) cout << x << '\n';
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