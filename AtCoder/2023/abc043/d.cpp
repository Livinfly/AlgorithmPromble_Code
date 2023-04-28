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
    string s;
    cin >> s;
    int n = s.size();
    if(n == 2) {
    	if(s[0] == s[1]) 
    		cout << "1 2\n";
    	else 
    		cout << "-1 -1\n";
    	return;
    }
    s = " "+s;
    for(char ch = 'a'; ch <= 'z'; ch ++) {
    	vector<int> sum(n+1);
    	for(int i = 1; i <= n; i ++) {
    		sum[i] = sum[i-1] + (s[i] == ch);
    	}
    	for(int i = 3; i <= n; i ++) {
    		if(sum[i]-sum[i-3] >= 2) {
    			cout << i-2 << ' ' << i << '\n';
    			return;
    		}
    	}
    }
    cout << "-1 -1\n";
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