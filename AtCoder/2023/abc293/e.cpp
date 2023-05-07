#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int qpm(int a, LL b, const int &c) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1LL*ans*a%c;
		a = 1LL*a*a%c;
		b >>= 1;
	}
	return ans;
}
int work(int a, LL x, const int &MO) {
	if(x == 0) return 1%MO;
	if(x == 1) return (a+1)%MO;
	if(x & 1) {
		return (1LL+qpm(a, x/2+1, MO))%MO*work(a, x/2, MO)%MO;
	}
	else {
		return ((1LL+qpm(a, x/2, MO))%MO*work(a, x/2-1, MO)%MO + qpm(a, x, MO)) % MO;
	}
}
void solve() {
    int a, m;
    LL x;
    cin >> a >> x >> m;
    cout << work(a, x-1, m) << '\n';
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