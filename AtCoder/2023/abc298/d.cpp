#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 6e5+10, MO = 998244353;

int q;
int l, n, hx[N], pow10[N];

int Hx(int l, int r) {
	return ((1LL*hx[r]-1LL*hx[l-1]*pow10[r-l+1]%MO)%MO+MO)%MO;
}
void solve() {
	pow10[0] = 1, hx[1] = 1, n = 1;
	for(int i = 1; i < N; i ++)
		pow10[i] = 1LL*pow10[i-1]*10%MO;
    cin >> q;
    while(q --) {
    	int op;
    	cin >> op;
    	if(op == 1) {
    		int x;
    		cin >> x;
    		hx[++ n] = (1LL*hx[n]*10%MO+x)%MO;
    	}
    	else if(op == 2) {
    		l ++;
    	}
    	else {
            // cout << l+1 << ' ' << n << '\n';
            // cout << hx[l] << ' ' << hx[n] << '\n';
            // for(int i = 0; i <= n; i ++)
            //     cout << hx[i] << " \n"[i == n];
    		cout << Hx(l+1, n) << '\n';
    	}
    }
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