#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const LL P = 1e9+7;

LL qpm(LL a, LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}
void solve() {
    LL n;
    cin >> n;
    LL res = (n*(n+1)%P*(2*n+1)%P*qpm(6, P-2)%P+n*(n-1)%P*(2*n-1)%P*qpm(6, P-2)%P+n*(n-1)%P*qpm(2,P-2)%P)%P;
    cout << 2022LL*res%P << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}