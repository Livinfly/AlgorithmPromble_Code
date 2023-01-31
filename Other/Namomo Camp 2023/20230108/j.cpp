#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;

void solve() {
    cin >> n;
    vector<LL> a(n);
    for(auto &x : a) cin >> x;
    LL Xor = 0, And = 0, Add = a[0]+a[1];
    for(int i = 2; i < n; i ++) Xor ^= a[i];
    // a+b = a^b + 2*(a&b)
    And = Add-Xor;
    // Xor是期望的值，而不是式子里确定的值，导致以下不合法的情况，包括下面需要判断的不合法也是因为这个
    if(Xor > Add || And % 2) {
        cout << "-1\n";
        return;
    }
    And /= 2;
    /*
        a^b a&b     a   b
         0   0  ->  0   0
         1   1  ->  x   x   (不合法)
         0   1  ->  1   1
         1   0  ->  不 同
    */
    LL ans = And;
    for(int i = 60; i >= 0; i --) {
        int xx = Xor>>i&1, yy = And>>i&1;
        if(xx && yy) {
            cout << "-1\n";
            return;
        }
        if(xx && !yy && (ans|1LL<<i) <= a[0]) {
            ans |= 1LL<<i;
        }
    }
    if(!ans || ans > a[0]) {
        cout << "-1\n";
        return;
    }
    cout << a[0]-ans << '\n';
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