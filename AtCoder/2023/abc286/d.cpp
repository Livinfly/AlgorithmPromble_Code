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
    int N, X;
    cin >> N >> X;
    bitset<10001> dp;
    dp[0] = 1;
    for(int i = 1; i <= N; i ++) {
    	int a, b;
    	cin >> a >> b;
    	for(int t = 1; t < b; t *= 2) {
    		dp |= dp << (a * t);
    		b -= t;
    	}
    	dp |= dp << (a * b);
    }
    cout << (dp[X] ? "Yes" : "No") << '\n';
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