#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool check(string s) {
	int n = s.size();
    bool ok = false;
	for(int i = 0; i < n/2; i ++) {
		if(s[i] != s[n-i-1]) ok = true;
	}
	return ok;
}
void solve() {
    string s;
    cin >> s;
    for(int i = s.size(); i > 1; i --) {
    	for(int j = 0; i+j <= s.size(); j ++) {
    		if(check(s.substr(j, i))) {
                // cout << s.substr(j, i) << '\n';
    			cout << i << '\n';
    			return;
    		}
    	}
    }
    cout << "-1\n";
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