#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e6+10, P = 1e9+7;

int n, m;
string s;
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
    for(int i = 1; i <= n+m; i ++)
        fact[i] = (LL)fact[i-1]*i%P;
    factInv[n+m] = qpm(fact[n+m], P-2);
    for(int i = n+m-1; i >= 0; i --)
        factInv[i] = (LL)factInv[i+1]*(i+1)%P;
}
int C(int n, int m) {
    return (LL)fact[n]*factInv[n-m]%P*factInv[m]%P;
}
void solve() {
    cin >> m >> s;
    n = s.size();
    PrevCalu();
    int res = 0;
    for(int i = n; i <= n+m; i ++) {
        res = ((LL)res+(LL)qpm(26, n+m-i)*qpm(25, i-n)%P*C(i-1, n-1)%P)%P;
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
C(i-1, n-1) 最后一位的位置确定了

n+|s|的字符串的子序列有s的个数
求方案，假设得到最终子串，贪心地选，即取连续的子串的第一个字母
xxxxxx|xxxx
子序列的最后到|的前一位，后面都有26种选法，前面都有25种选法
*/