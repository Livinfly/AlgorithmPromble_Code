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
    map<string, int> mp;
    vector<string> s(n);
    for(auto &x : s) {
        cin >> x;
        mp[x] ++;
        mp[x.substr(0, 1)+"#"] ++;
        mp["#"+x.substr(1, 1)] ++;
    }
    LL res = 0;
    for(auto x : s) {
        mp[x] --;
        mp[x.substr(0, 1)+"#"] --;
        mp["#"+x.substr(1, 1)] --;
        n --;
        res += mp[x.substr(0, 1)+"#"] + mp["#"+x.substr(1, 1)] - 2*mp[x];
        // cout << res << '\n';
    }
    cout << res << '\n';
    // cout << "--------------\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}