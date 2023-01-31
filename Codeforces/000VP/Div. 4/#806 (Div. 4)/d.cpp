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
    vector<string> s(n);
    set<string> st;
    for(auto &x : s)
        cin >> x, st.insert(x);
    for(auto str : s) {
        bool ok = false;
        for(int i = 0; i < str.size(); i ++) {
            string s1 = str.substr(0, i), s2 = str.substr(i);
            if(st.count(s1) && st.count(s2)) {
                ok = true;
                break;
            }
        }
        if(ok) cout << "1";
        else cout << "0";
    }
    cout << '\n';
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