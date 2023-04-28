#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10, MO = 1e9+7;

int n, m;
int fact[N], factInv[N];

int qpm(int a, int b, const int &c = MO) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1LL*ans*a%MO;
		a = 1LL*a*a%MO;
		b >>= 1;
	}
	return ans;
}
void PrevCalc(int n) {
	fact[0] = 1;
	for(int i = 1; i <= n; i ++) 
		fact[i] = 1LL*fact[i-1]*i%MO; // LL 

	factInv[n] = qpm(fact[n], MO-2);
	for(int i = n-1; i >= 0; i --) 
		factInv[i] = 1LL*factInv[i+1]*(i+1)%MO;
}
int C(int n, int m) {
	if(n < m || m < 0) return 0;
	return 1LL*fact[n]*factInv[n-m]%MO*factInv[m]%MO;
}
void solve() {
	PrevCalc(N-10);
    int a, b;
    cin >> n >> m >> a >> b;
    int ans = 0;
    for(int i = 0; i < n-a; i ++) {
    	// cout << n-a+b-1 << ' ' << i << " --- " << n+m-2-(n-a+b-1) << ' ' << n-1-i << '\n';
    	// cout << C(n-a+b-1, i) << ' ' << C(n+m-2-(n-a+b-1), n-1-i) << '\n';
    	ans = (1LL*ans+1LL*C(n-a+b-1, i)*C(n+m-2-(n-a+b-1), n-1-i)%MO)%MO;
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