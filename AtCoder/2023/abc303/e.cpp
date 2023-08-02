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
    vector<vector<int>> e(n+1);
    vector<int> deg(n+1);
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        deg[a] ++, deg[b] ++;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i ++) {
        if(deg[i] > 2) {
            ans.push_back(deg[i]);
            for(auto v : e[i]) {
                e[v].clear();
            }
            e[i].clear();
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(e[i].size()) cnt ++;
    }
    cnt /= 3;
    while(cnt --) ans.push_back(2);
    sort(all(ans));
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << " \n"[i+1 == ans.size()];
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}