#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 6010, P = 998244353;

int TTT = 0;
int frac[N], f[N][N], inv[N], sum[N];

int qpm(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = (LL)ans*a%P;
        a = (LL)a*a%P;
        b >>= 1;
    }
    return ans;
}
void PrevCalu() {
    frac[0] = 1;
    for(int i = 1; i <= N-10; i ++) 
        frac[i] = (LL)frac[i-1]*i%P;
    for(int i = 1; i <= N-10; i ++)
        inv[i] = qpm(i, P-2);
    for(int i = 1; i <= N-10; i ++) 
        f[i][0] = (LL)i*(i-1)%P*inv[4]%P;
    for(int i = 1; i <= N-10; i ++) {
        sum[0] = ((LL)sum[0]+f[i-1][0])%P;
        for(int j = 1; j <= N-10; j ++) 
            f[i][j] = (LL)sum[j-1]*2%P*inv[i]%P;
        for(int j = 1; j <= N-10; j ++) 
            sum[j] = ((LL)sum[j]+f[i][j])%P;
    }
}
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    int res = (LL)f[n][k-1]*frac[n]%P;
    printf("Case #%d: %d\n", ++ TTT, res);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    PrevCalu();
    int Tcase;
    scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    return 0;
}