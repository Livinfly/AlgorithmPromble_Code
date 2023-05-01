#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MO = 998244353;

int inv5;
LL n;
map<LL, int> f;

int qpm(int a, int b, const int &c = MO) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1LL*ans*a%MO;
		a = 1LL*a*a%MO;
		b >>= 1;
	}
	return ans;
}
int dfs(LL u) {
	if(u > n) return 0;
	if(u == n) return 1;
	if(f.count(u)) return f[u];

	for(int i = 2; i <= 6; i ++) {
		// cout << dfs(1LL*u*i) << '\n';
		f[u] = (f[u] + dfs(1LL*u*i)) % MO;
	}
	f[u] = 1LL*f[u]*inv5%MO;

	return f[u];
}
void solve() {
	inv5 = qpm(5, MO-2);
    cin >> n;
    cout << dfs(1) << '\n';
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