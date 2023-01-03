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
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n); // can't use a[n]
    LL res = 0;
    for(LL i = n-1; i >= 2; i --) { // i -> gcd & cost
        LL k = i-1; // edge can choose in one group
        a[i] = (n/i)*(n/i-1)/2;
        for(LL j = i*2; j < n; j += i)
            a[i] -= a[j];
        LL edges = a[i]/k*k;
        if(edges > m) 
            edges = m/k*k;
        m -= edges;
        res += edges/k*i;
    }
    if(m > 0) res = -1;
    cout << res << '\n';
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