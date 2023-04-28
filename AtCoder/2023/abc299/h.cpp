#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int I = 1e9, MO = 998244353;

int R, cnt = 0;
map<int, int> dp;

int qpm(int a, int b, const int &c = MO) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1LL*ans*a%c;
		a = 1LL*a*a%c;
		b >>= 1;
	}
	return ans;
}
int dfs(int sum) {
	if(sum-R > I) return 0;
	if(sum-R && I % (sum-R) == 0) {
		return 1;
	}
	if(dp.count(sum)) {
		return dp[sum];
	}
	int res = 0;
	for(int i = 1; i <= 6; i ++) {
		res = (res + dfs(sum+i)) % MO;
		// cout << res << endl;
	}
	res = 1LL*res*qpm(6, MO-2)%MO;
	return dp[sum] = res;
}
void solve() {
    cin >> R;
    int res = 0;
    for(int i = 1; i <= 6; i ++)
    	res = (res + dfs(i)%MO) % MO;
    res = 1LL*res*qpm(6, MO-2)%MO;
    cout << res << '\n';
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