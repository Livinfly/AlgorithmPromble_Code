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
    map<int, int> row, col, dia, rdia;
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        row[a]++, col[b]++, dia[a+b]++, rdia[a-b]++;
    }
    LL ans = 0;
    for(auto [_, v]: row) {
        ans += 1LL*v*(v-1);
    }
    for(auto [_, v]: col) {
        ans += 1LL*v*(v-1);
    }
    for(auto [_, v]: dia) {
        ans += 1LL*v*(v-1);
    }
    for(auto [_, v]: rdia) {
        ans += 1LL*v*(v-1);
    }
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