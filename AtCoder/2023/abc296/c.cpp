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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &x : a) {
    	cin >> x;
    }
    sort(all(a));

    for(auto xx : a) {
    	int y = *lower_bound(all(a), xx+abs(x));
    	if(abs(y-xx) == abs(x)) {
    		cout << "Yes\n";
    		return;
    	}
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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