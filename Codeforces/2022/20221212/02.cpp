#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> st;
    string t, tt;
    tt = s.substr(0, 2);
    for(int i = 1; i+1 < s.size(); i ++) {
        string t = s.substr(i, 2);
        if(st.find(t) != st.end()) {
            cout << "YES\n";
            return;
        }
        st.insert(tt);
        tt = t;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}