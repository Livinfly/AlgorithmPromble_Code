#pragma GCC optimize(2)

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
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        auto &[x, id] = a[i];
        cin >> x;
        id = i;
    }
    sort(all(a));
    vector<int> col(n), ans(n);
    vector<vector<int>> e(n);
    function<bool(int)> dfs = [&](int u) {
        for(auto v: e[u]) {
            if(col[v] == col[u]) return false;
            if(col[v] == -1) {
                col[v] = col[u] ^ 1;
                if(!dfs(v)) return false;
            }
        }
        return true;
    };
    auto check = [&](int mid) {
        for(int i = 0; i < n; i ++) {
            e[i].clear(), col[i] = -1;
        }
        for(int i = 0; i < n; i ++) {
            for(int j = i+1; j < n && j <= i+3; j ++) {
                if((a[i][0]^a[j][0]) <= mid) {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n; i ++) {
            if(col[i] == -1) {
                col[i] = 0;
                if(!dfs(i)) return false;
            }
        }
        return true;
    };
    int l = 0, r = 1<<30;
    while(l < r) {
        int mid = 1LL*l+r+1 >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    check(r); // 必然有解
    for(int i = 0; i < n; i ++) {
        auto [_, id] = a[i];
        ans[id] = col[i];
    }
    for(int i = 0; i < n; i ++) {
        cout << ans[i];
    }
    cout << '\n';
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