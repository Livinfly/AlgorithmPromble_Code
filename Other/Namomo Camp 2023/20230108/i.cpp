#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5+10, P = 1e9+7;

int n, m;
int fact[N], factInv[N];

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
    fact[0] = 1;
    int mx = max(n, m); // ...
    for(int i = 1; i <= mx; i ++) 
        fact[i] = (LL)fact[i-1]*i%P;
    factInv[mx] = qpm(fact[mx], P-2);
    for(int i = mx-1; i >= 0; i --)
        factInv[i] = (LL)factInv[i+1]*(i+1)%P;
}
int A(int n, int m) {
    return (LL)fact[n]*factInv[n-m]%P;
}
int C(int n, int m) {
    return (LL)fact[n]*factInv[n-m]%P*factInv[m]%P;
}
void solve() {
    cin >> n >> m;
    PrevCalu();
    int res = 0;
    for(int i = 0; i <= n; i ++) {
        int x = (LL)C(n, i)*A(m, i)%P*A(m-i, n-i)%P*A(m-i, n-i)%P;
        res = ((LL)res + ((i&1) ? -1 : 1)*x)%P;
        res = ((LL)res+P)%P;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*


从全错排的推导可以过来
https://zhuanlan.zhihu.com/p/133818995

1. 容斥原理
    也先和普通的全错排证明一样，先确定某几个位置A, B相同 a_i == b_i --- C(n, i)
    在把这i个数填上                                              --- A(m, i)
    在剩下的位置A和B都随便放                                      --- A(m-i, n-i) * A(m-i, n-i)

    或者，先确定一种选数，C(n, i) * A(m-i, n-i)，确定i个位置确定A B相同时的方案数
    再可以打乱顺序  A(m, n)

（DP我现在也不是很看得懂，只先写了普通错排的DP的方法）
2. DP
    f[i], 为i位错排的方案数
    对即将要放的数，同普通的全错排的考虑
    将i放在k的位置，若k在i的位置，那么就不用考虑i和k了，剩下的错排
    再考虑有i-1种可能这样的情况                                   --- (i-1)*f[i-2]
    将i放在k的位置，而k不在i的位置，那么不管i（i已经合法，即已经错排）
    而这种情况，我们预设k不在i，那就可以把i的位置当作k的原本的位置
    除i外的i-1个数错排的方案数                                    --- (i-1)*f[i-1]
*/