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
    vector<LL> a(n*m);
    for(auto &x : a) cin >> x;
    sort(all(a));
	LL ans = (a[n*m-1]-a[0])*(max(n, m)-1)*min(n, m) + (a[n*m-2]-a[0])*(min(n, m)-1);
	ans = max(ans, (a[n*m-1]-a[0])*(max(n, m)-1)*min(n, m) + (a[n*m-1]-a[1])*(min(n, m)-1));
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