#pragma GCC optimize(2)

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
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    vector<int> n1(n+2), p0(n+2);
    int p = 0;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == '0') p = i;
        p0[i] = p;
    }
    p = n+1;
    for(int i = n; i >= 1; i --) {
        if(s[i] == '1') p = i;
        n1[i] = p;
    }
    set<PII> st;
    while(m --) {
        int l, r;
        cin >> l >> r;
        l = n1[l], r = p0[r];
        if(r < l) st.insert({0, 0});
        else st.insert({l, r});
    }
    cout << st.size() << '\n';
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