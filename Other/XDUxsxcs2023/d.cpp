#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MO = 1e9+7;

int qpm(int a, int b, const int &c = MO) { // int/LL
	int ans = 1 % c;
	while(b) {
		if(b & 1) ans = 1LL*ans*a % c;
		a = 1LL*a*a % c;
		b >>= 1;
	}
	return ans;
}

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(a == b && y <= x) {
    	cout << "forever\n";
    	return;
    }
    int p = 1LL*a*qpm(b, MO-2) % MO, d = x/y, r = x%y;
    // cerr << y << ' ' << p << ' ' << d << ' ' << r << '\n';
    int ans = (1LL*y * (qpm(1-p, d) - 1)%MO * qpm(1LL*qpm(1-p, d) * (-p)%MO, MO-2) + r)% MO;
    ans = (ans + MO) % MO;
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