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
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> b(n+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	b[a[i]].push_back(i);
    }
   	LL ans = 0;
   	for(int i = 1; i <= n; i ++) {
   		ans += 1LL*(i/2)*(n-i+1);
   	}
    for(int i = 1; i <= n; i ++) {
    	int l = 0, r = b[i].size()-1;
    	while(l < r) {
    		if(b[i][l] < n-b[i][r]+1) {
    			ans -= 1LL*(r-l) * b[i][l];
    			l ++;
    		}
    		else {
    			ans -= 1LL*(r-l) * (n-b[i][r]+1);
    			r --;
    		}
    	}
    }
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}