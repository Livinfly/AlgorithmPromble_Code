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
    string s; cin >> s;
    bool ok = false;
    for(int i = 1; i < s.size(); i ++) {
        if(s[i-1] == ')' && s[i] == '(') {
            ok = true;
            break;
        }
    }
    string ans = "";
    if(ok) {
        for(auto x: s) ans += '(';
        for(auto x: s) ans += ')';
    }
    else {
        for(auto x: s) ans += "()";
    }
    if(!ans.find(s)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << ans << '\n';
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