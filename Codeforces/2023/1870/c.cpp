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
    int n, k; cin >> n >> k;
    vector<array<int, 2>> a(n+1);
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(1+all(a));
    int l = 1, r = n;
    vector<int> ans(k+1);
    vector<bool> vis(n+2);
    for(int i = 1; i <= n; i ++) {
        auto [x, id] = a[i];
        // cerr << x << ' ' << id << ' ' << l << ' ' << r << '\n';
        if(l <= r && !ans[x]) {
            // cerr << x << ' ' << l << ' ' << r << '\n';
            ans[x] = (r-l+1)*2;
        }
        vis[id] = true;
        while(vis[l]) l++;
        while(vis[r]) r--;
    }
    for(int i = 1; i <= k; i ++) {
        cout << ans[i] << " \n"[i==k];
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}