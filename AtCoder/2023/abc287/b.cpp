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
   	vector<string> s(n);
   	set<string> st;
   	for(auto &x : s) cin >> x;
   	for(int i = 0; i < m; i ++) {
   		string t;
   		cin >> t;
   		st.insert(t);
   	}
   	int cnt = 0;
   	for(auto x : s) {
   		if(x.size() >= 3 && st.count(x.substr(x.size()-3, 3))) {
            // cout << x.substr(x.size()-3, 3) << '\n';
   			cnt ++;
   		}
   	}
   	cout << cnt << '\n';
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