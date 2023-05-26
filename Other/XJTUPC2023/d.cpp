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
    vector<PII> p(n);
    PII a(100, 100), b(-100, -100);
    bool flag = false;
    for(auto &[x, y] : p) {
    	cin >> x >> y;
    	a.fi = min(a.fi, x);
    	a.se = min(a.se, y);
    	b.fi = max(b.fi, x);
    	b.se = max(b.se, y);
        if(!x && !y) flag = true;
    }
    int ans = (b.fi-a.fi+1)*(b.se-a.se+1);
    // cerr << ans << '\n';
    if(n != ans || !flag) {
    	cout << "-1\n";
    }
    else {
    	cout << b.fi-a.fi+b.se-a.se << '\n';
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}