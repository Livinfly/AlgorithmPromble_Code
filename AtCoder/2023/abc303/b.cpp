#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool st[55][55];

void solve() {
    int n, m;
    cin >> n >> m;
    while(m --) {
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        for(int i = 1; i < n; i ++) {
            if(i) {
                st[a[i]][a[i-1]] = st[a[i-1]][a[i]] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i+1; j <= n; j ++) {
            if(!st[i][j]) {
                cnt ++;
            }
        }
    }
    cout << cnt << '\n';
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