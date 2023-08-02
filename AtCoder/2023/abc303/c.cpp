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
    int n, m, h, k, x = 0, y = 0;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<PII> st;
    while(m --) {
        int a, b;
        cin >> a >> b;
        st.insert({a, b});
    }
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'R') {
            x ++;
        }
        else if(s[i] == 'L') {
            x --;
        }
        else if(s[i] == 'U') {
            y ++;
        }
        else {
            y --;
        }
        h --;
        if(h < 0) {
            cout << "No\n";
            return;
        }
        PII p = {x, y};
        if(h < k && st.count(p)) {
            h = max(h, k);
            st.erase(p);
        }
    }
    cout << "Yes\n";
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