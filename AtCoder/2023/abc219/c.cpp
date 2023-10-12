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
    map<char, char> mp;
    string T; cin >> T;
    for(int i = 0, x = 'a'; x <= 'z'; i++, x++) {
        mp[T[x-'a']] = x;
    }
    int n; cin >> n;
    vector<string> ve(n);
    for(auto &s: ve) cin >> s;
    vector<string> rve = ve;
    for(auto &s: rve) 
        for(auto &x: s) 
            x = mp[x];
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b) {
        return rve[a] < rve[b];
    });
    for(auto x: order) 
        cout << ve[x] << '\n';
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