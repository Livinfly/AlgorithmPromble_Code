#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int qpm(int a, int b, const int &c) { // int/LL
	int ans = 1 % c;
	while(b) {
		if(b & 1) ans = 1LL*ans*a % c;
		a = 1LL*a*a % c;
		b >>= 1;
	}
	return ans;
}

void solve() {
	// 16
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = s.substr(n/2);
    n /= 2;
   	reverse(all(s));
   	// cerr << s << '\n';
   	for(auto &x : s) {
   		x = (char)((x - 'a' + 16) % 26 + 'a');
   	}
   	string ans = s;
   	for(int i = 0, cur = 0, k = 25; i < m; i ++, cur ++) {
   		if(cur == s.size()) {
   			// cerr << s << '\n';
   			s = ans;
   			// cerr << s << '\n';
   			cur = 0;
   		}
   		ans += (char)((s[cur] - 'a' + k) % 26 + 'a');
   	}
   	// cerr << ans.size() << '\n';
   	ans = ans.substr(0, m);
   	reverse(all(ans));
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