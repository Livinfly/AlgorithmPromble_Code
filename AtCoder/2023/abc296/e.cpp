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
    vector<int> a(n+1), deg(n+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
        deg[a[i]] ++;
    }
    auto TopoSort = [&]() {
        queue<int> q;
        for(int i = 1; i <= n; i ++) {
            if(!deg[i]) {
                q.push(i);
            }
        }
        while(q.size()) {
            auto u = q.front();
            q.pop();
            if(-- deg[a[u]] == 0) {
                q.push(a[u]);
            }
        }
    };
    TopoSort();
    int ans = 0;
    for(auto x : deg) {
        ans += x;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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