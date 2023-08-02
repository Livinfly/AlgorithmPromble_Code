#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool check(int mid, string a, string b) {
	int n1 = a.size(), n2 = b.size();
	set<string> st;
	for(int i = 0; i+mid-1 < n1; i ++) {
		string t = a.substr(i, mid);
		st.insert(t);
	}
	for(int i = 0; i+mid-1 < n2; i ++) {
		string t = b.substr(i, mid);
		if(st.count(t)) {
			return true;
		}
	}
	return false;
}
int GetAns(string a, string b) {
	int l = 0, r = min(a.size(), b.size());
	// cerr << l << ' ' << r << '\n';
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid, a, b)) l = mid;
		else r = mid - 1;
	}
	return r;
}
void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &x : a) cin >> x;
   	int ans = 0;
	for(int i = 0; i < n; i ++) {
		auto s1 = a[i];
		for(int j = i+1; j < n; j ++) {
			auto s2 = a[j];
			ans = max(ans, GetAns(s1, s2));
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}