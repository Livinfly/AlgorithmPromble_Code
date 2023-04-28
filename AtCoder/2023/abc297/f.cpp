#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int NN = 1e6+10, MO = 998244353;

LL h, w, k;
LL fact[NN], factInv[NN];

LL qpm(LL a, LL b, const LL &c = MO) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans*a%c;
        a = a*a%c;
        b >>= 1;
    }
    return ans;
}
void PrevCalc() {
    fact[0] = 1;
    for(int i = 1; i < NN; i ++) 
        fact[i] = fact[i-1]*i%MO;
    factInv[NN-1] = qpm(fact[NN-1], MO-2);
    for(int i = NN-2; i >= 0; i --) 
        factInv[i] = factInv[i+1]*(i+1)%MO;
}
LL C(int n, int m) {
    if(n < m || m < 0) return 0;
    return fact[n]*factInv[n-m]%MO*factInv[m]%MO;
}
void solve() {
    PrevCalc();
    cin >> h >> w >> k;
    if(k == 1) {
        cout << 1 << '\n';
        return;
    }
    // cout << C(4, 2) << '\n';
    LL res = qpm(C(h*w, k), MO-2), sum = 0;
    for(int i = 1; i <= h; i ++) 
        for(int j = 1; j <= w; j ++) {
            LL way = 0;
            for(int v1 = 0; v1 <= 2; v1 ++)
                for(int v2 = 0; v2 <= 2; v2 ++) {
                    // neat way to inclusion-exclusion
                    int t = C((i-v1)*(j-v2), k)%MO*(v1==1 ? -2 : 1)%MO*(v2==1 ? -2 : 1);
                    way = ((way+t)%MO+MO)%MO;
                }
            sum = (sum+i*j%MO*(h-i+1)%MO*(w-j+1)%MO*way)%MO;
        }
    res = res * sum % MO;
    cout << (res+MO)%MO << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}