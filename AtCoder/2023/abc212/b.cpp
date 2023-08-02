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
    string s;
    cin >> s;
    set<char> st;
    for(auto x: s) st.insert(x);
    if(st.size() == 1) {
        cout << "Weak\n";
        return;
    }
    bool ok = false;
    for(int i = 1; i < 4; i ++) {
        int l = s[i-1]-'0', r = s[i]-'0';
        if((l+1)%10 != r) {
            ok = true;
            break;
        }
    }
    if(ok) cout << "Strong\n";
    else cout << "Weak\n";
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