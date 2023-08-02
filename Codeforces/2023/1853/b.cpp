#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2;

LL n, m;
LL f1[N] = {0, 1};
LL A[N][N] = {
    {0, 1,},
    {1, 1},
};

void mul(LL c[], LL a[], LL b[][N]) {
    LL tmp[N] = {};
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            tmp[i] = tmp[i]+a[j]*b[j][i];
    memcpy(c, tmp, sizeof tmp);
}
void mul(LL c[][N], LL a[][N], LL b[][N]) {
    LL tmp[N][N] = {};
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            for(int k = 0; k < N; k ++)
                tmp[i][j] = tmp[i][j]+a[i][k]*b[k][j];
    memcpy(c, tmp, sizeof tmp);
}
void ExGcd(LL a, LL b, LL &d, LL &x, LL &y) {
    if (!b) d = a, x = 1, y = 0;
    else ExGcd(b, a % b, d, y, x), y -= x * (a / b);
}
void init() {
    f1[0] = 0, f1[1] = 1;
    A[0][0] = 0, A[1][0] = A[0][1] = A[1][1] = 1;
}
void solve() {
    init();
    LL n, k;
    cin >> n >> k;
    if(k > 30) {
        cout << 0 << '\n';
        return;
    }
    // k = 28;
    k --;
    while(k) {
        if(k & 1) mul(f1, f1, A);
        mul(A, A, A);
        k >>= 1;
    }
    // f_{k, k+1}
    if(n < f1[0]) {
        cout << 0 << '\n';
        return;
    }
    LL d, x, y;
    ExGcd(f1[0], f1[1], d, x, y);
    if(n % d) {
        cout << 0 << '\n';
        return;
    }
    n /= d;
    x *= n, y *= n;
    LL ans = 0;
    LL tx = x, ty = y;
    tx = (x%f1[1]+f1[1]) % f1[1];
    ty = y - (tx-x)/f1[1] * f1[0];
    // cerr << 1 << '\n';
    // cerr << f1[0] << ' ' << f1[1] << '\n';
    // cerr << x << ' ' << y << ' ' << tx << ' ' << ty << '\n';
    // cout << a << ' ' << b << '\n';
    if(ty < 0) {
        cout << 0 << '\n';
        return;
    }
    cout << ty/f1[0] + 1 << '\n';
}
void solve1() {
    LL n, k;
    cin >> n >> k;
    if(k > 30) {
        cout << 0 << '\n';
        return;
    }
    LL a = 0, b = 1;
    for(int i = 1; i < k; i ++) {
        swap(a, b);
        b += a;
    }
    LL ans = 0;
    for(LL x = 0; x <= n; x ++) {
        LL t = n - x*a;
        if(t % b) continue;
        if(t / b >= 0) ans ++;
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}