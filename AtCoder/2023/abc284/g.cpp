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
    int n, m;
    cin >> n >> m;
    vector<int> pn(n);
    pn[0] = 1;
    for(int i = 1; i < n; i ++) {
    	pn[i] = 1LL*pn[i-1] * n % m;
    }
    int ans = 0, permu = 1;
    for(int i = 1; i <= n; i ++) {
    	ans = (1LL*ans + 1LL*permu * pn[n-i] % m * (1LL*i*(i-1)/2%m) % m) % m;
    	permu = 1LL*permu * (n-i) % m;
    }
   	cout << 1LL*ans * n % m << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}