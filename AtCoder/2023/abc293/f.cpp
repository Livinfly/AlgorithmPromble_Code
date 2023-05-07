#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL n;

LL check(int st, LL b) {
    LL ans = 0;
    for(int i = 0; i < 6; i ++) {
        if(ans > (n-((st>>i)&1)) / b) return n+1;
        ans = ans*b + (st>>i & 1);
    }
    return ans;
}
void solve() {
    cin >> n;
    int ans = 0;
    for(int i = 2; i <= 1000; i ++) {
    	LL t = n;
    	while(t) {
    		if(t % i > 1) break;
    		t /= i;
    	}
    	if(!t) ans ++;
    }
    for(int i = 0; i < (1<<6); i ++) {
        LL l = 1001, r = n;
        while(l < r) {
            LL mid = l+r >> 1;
            if(check(i, mid) < n) {
                l = mid+1;
            }
            else r = mid;
        }
        ans += (r > 1000 && check(i, r) == n);
    }
    cout << ans << '\n';
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