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
    int n, k;
    cin >> n >> k;
    vector<LL> a(n+2), s(n+2);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
		s[i] = s[max(i-k, 0)] + a[i];
    }
    int q;
    cin >> q;
    while(q --) {
    	int l, r;
    	cin >> l >> r;
    	vector<LL> b(k);
        for(int i = r; r-i+1 <= k; i --) {
            b[i%k] += s[i];
        }
        for(int i = l-1; i >= 0 && l-i <= k; i --) {
            b[i%k] -= s[i];
        }
    	
    	cout << (b == vector<LL>(k, b[0]) ? "Yes" : "No") << '\n';
    }
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