#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, MO = 998244353;

int n, A, B, P, Q;
int w[N][N];
bool st[N][N];

PII operator + (const PII &a, const PII &b) {
	return {(1LL*a.fi+b.fi)%MO, (1LL*a.se+b.se)%MO};
}

int qpm(int a, int b, const int &c = MO) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1LL*ans*a%c;
		a = 1LL*a*a%c;
		b >>= 1;
	}
	return ans;
}
int dfs(int pa, int pb) {
	if(pa >= n || pb >= n) {
		return pa >= n;
	}
	if(st[pa][pb]) {
		return w[pa][pb];
	}
	int s = 0;
	for(int i = 1; i <= P; i ++)
		for(int j = 1; j <= Q; j ++)
			 s = (s+dfs(pa+i, pb+j))%MO;
	w[pa][pb] = 1LL*s*qpm(P*Q, MO-2)%MO;
	// cout << pa << ' ' << pb << ' ' << wt[pa][pb].se << '\n';
	st[pa][pb] = true;
	return w[pa][pb];
}
void solve() {
    cin >> n >> A >> B >> P >> Q;
    int ans = dfs(A, B);
    // cout << ans.fi << ' ' << ans.se << '\n';
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