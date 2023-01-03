#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e7;

int cnt, prime[N], st[N+1];

void GetPrimes() {
    for(int i = 2; i <= 10000000; i ++){
        if(!st[i]) prime[cnt ++] = i, st[i] = i;
        for(int j = 0; prime[j] <= 10000000 / i; j ++) {
            int t = prime[j]*i;
            st[t] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}
void solve() {
    int a, b;
    cin >> a >> b;
    if(a+1 == b) {
        cout << "-1\n";
        return;
    }
    if(__gcd(a, b) > 1) {
        cout << "0\n";
        return;
    }
    int dx = b-a;
    // vector<int> divs;
    int res = 1e9;
    while(dx > 1) {
        int x = st[dx];
        res = min(res, x-(a-a/x*x));
        // cout << dx << '\n';
        dx /= st[dx];
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    GetPrimes();
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}