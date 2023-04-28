#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    LL n;
    cin >> n;
    for(LL i = 2; i*i*i <= n; i ++) {
        LL t = (LL)i*i;
        if(n % i == 0) {
            LL m = n/i;
            if(m % i == 0) {
                cout << i << ' ' << n/t << '\n';
                return;
            }
            else {
                cout << (LL)(sqrt(m)+0.1) << ' ' << i << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;
    while(T --) 
        solve();
    return 0;
}
/*
开根号加eps就行了（
p, q 肯定有比n根号3次小的
*/