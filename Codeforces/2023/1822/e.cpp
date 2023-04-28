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
    string s;
    cin >> s;
    if(n & 1) {
        cout << "-1\n";
        return;
    }

    map<char, int> mp;
    int mx = 0;
    for(auto x : s)
    	mp[x] ++;
    for(auto [x, y] : mp) 
        mx = max(mx, y);
    if(mx > n/2) {
        // cout << "???????\n";
    	cout << "-1\n";
    	return;
    }
    mp.clear();
    int wait = 0, tot = 0;
    mx = 0;
    for(int i = 0; i < n/2; i ++) {
    	if(s[i] == s[n-i-1]) {
    		mp[s[i]] ++;
    		tot ++;
    	}
    }
    
    for(auto [k, v] : mp)
    	mx = max(mx, v);
    if(mx*2 > tot) {
        cout << mx << '\n';
        return;
    }
    if(tot & 1) {
        cout << tot/2+1 << '\n';
    }
    else {
    	cout << tot/2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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