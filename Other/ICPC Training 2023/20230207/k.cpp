#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+10, MO = 998244353;

LL n, k;
LL fact[N], factInv[N];
LL f[N];

LL qpm(LL a, LL b, const int &c = MO) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans*a%c;
        a = a*a%c;
        b >>= 1;
    }
    return ans;
}
LL C(int n, int m) {
    return fact[n]*factInv[n-m]%MO*factInv[m]%MO;
}
LL work(int u) {
    LL res = 0;
    for(int i = (k+1)/2; i <= k; i ++)
        res = (res+C(k, i)*qpm(u, i)%MO*qpm(n-u, k-i)%MO)%MO;
    return res;
}
LL fff(LL n, LL k) {
    return (LL)qpm(n, k-1)*(n*(n+1)%MO*qpm(2, MO-2)%MO)%MO;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
        f[i] = 1;
    LL res = 0;
    for(int i = n; i > 0; i --) {
        f[i] = (qpm(n, k)-work(i-1))%MO;
        for(int j = i+1; j <= n; j ++)
            f[i] = (f[i]-f[j])%MO;
        f[i] = (f[i]+MO)%MO;
    }
    for(int i = 1; i <= n; i ++) {
        cout << f[i] << " \n"[i == n];
        res = (res + f[i]*i%MO)%MO;
    }
    cout << res << '\n';
    cout << fff(n, k) << endl;
    // cout << (LL)(fff(n, k)-fff(n, k-1)+fff(n-1, k)%MO+MO)%MO << '\n';
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
    fact[0] = 1;
    for(int i = 1; i <= N-10; i ++)
        fact[i] = fact[i-1]*i%MO;
    factInv[N-10] = qpm(fact[N-10], MO-2);
    for(int i = N-11; i >= 0; i --)
        factInv[i] = factInv[i+1]*(i+1)%MO;
    while(true) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}
/*

*/