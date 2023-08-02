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
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<vector<int>> f(n);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
        int c;
        cin >> c;
        while(c --) {
            int x;
            cin >> x;
            f[i].push_back(x);
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            bool ok = true;
            if(p[i] >= p[j]) {
                for(auto x : f[i]) {
                    if(lower_bound(all(f[j]), x) == f[j].end()) {
                        ok = false;
                        break;
                    }
                }
                if(ok && (p[i] > p[j] || f[i].size() < f[j].size())) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
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