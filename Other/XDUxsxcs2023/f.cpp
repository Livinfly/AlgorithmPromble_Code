#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int base = 2e5;

int delta;
LL ans, res;
int rec[base<<1];

void solve() {
    LL n, negE = 0, negO = 0, posE = 0, posO = 0, zero = 0;
    cin >> n;
    while(n --) {
    	LL x;
    	cin >> x;
    	if(x & 1) {
    		delta ++;
    		res = res - negO + posE*2 - posO + 2*zero + 2;
    		rec[base-delta+1] ++;
    		swap(posO, posE);
    		posO += zero;
    		posO ++;
    		swap(negO, negE);
    		zero = rec[base-delta];
    		negE -= zero;
    	}
    	else {
    		delta --;
    		res = res + negE + posE - 2*posO + zero + 1;
    		rec[base-delta-1] ++;
    		swap(posO, posE);
    		swap(negO, negE);
    		negO += zero;
    		negO ++;
    		zero = rec[base-delta];
    		posE -= zero;
    	}
    	// cerr << posO << ' ' << posE << ' ' << negO << ' ' << negE << '\n';
    	ans += res;
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
/*
odd - even    -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6
			   3  3  2  2  1  1 0 2 1 3 2 4 3
*/