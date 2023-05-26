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
    LL d, k, x;
    cin >> d >> k >> x;
    LL  ans = 1e18;
    vector<LL> a(d+1);
    a[0] = 1;
    for(int i = 1; i <= d; i ++) {
    	a[i] = a[i-1]*k + 1;
    }
    for(int i = 0; i <= d; i ++) {
    	if(a[i] >= x) {
    		LL res = (i < d);
    		LL cut = a[i]-x;
    		for(int j = i-1; j >= 0; j --) {
    			LL l = cut/a[j];
    			cut -= a[j]*l;
    			res += l;
    		}
    		ans = min(ans, res);
    	}
    }
    cout << ans << "\n";
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