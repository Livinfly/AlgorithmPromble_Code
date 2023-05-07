#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

void solve() {
    LL l, n1, n2;
    cin >> l >> n1 >> n2;
    vector<PLL> v1(n1), v2(n2);
    for(auto &[x, y] : v1)
    	cin >> x >> y;
    for(auto &[x, y] : v2)
    	cin >> x >> y;
    LL l1 = 0, l2 = 0, ans = 0;
    int i = 0, j = 0;
    while(i < n1 || j < n2) {
    	if(l1 <= l2) {
            auto [x1, y1] = v1[i ++];
    		if(j && v2[j-1].fi == x1) {
    			ans += min(l2-l1, y1);
    		}
    		l1 += y1;
    	}
    	else {
        	auto [x2, y2] = v2[j ++];
    		if(i && v1[i-1].fi == x2) {
    			ans += min(l1-l2, y2);
    		}
    		l2 += y2;
    	}
        // cout << l1 << ' ' << l2 << ' ' << ans << '\n';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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