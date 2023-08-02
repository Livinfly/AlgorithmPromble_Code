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
    LL n, k;
    cin >> n >> k;
    map<int, LL> mp;
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    LL sum = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); it ++) {
        sum += it->se;
        if(sum > k) {
            cout << it->fi + 1 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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