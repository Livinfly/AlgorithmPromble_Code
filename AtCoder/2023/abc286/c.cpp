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
	int n, a, b;
	string s;
	cin >> n >> a >> b;
	cin >> s;
	s += s;
    LL ans = 1e18;
    for(int i = 0; i < n; i ++) {
    	LL res = 1LL*i * a;
    	int j = i+n-1, cnt = 0;
    	for(int k = 0; k < n/2; k ++) {
    		if(s[i+k] != s[j-k]) {
    			cnt ++;
    		}
    	}
    	res += 1LL*cnt * b;
    	ans = min(ans, res);
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}