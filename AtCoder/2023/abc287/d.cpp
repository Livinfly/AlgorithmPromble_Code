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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int cnt = 0;
    for(int i = 0; i < m; i ++) {
    	if(s[n-i-1] != t[m-i-1] && s[n-i-1] != '?' && t[m-i-1] != '?') {
    		cnt ++;
    	}
    }
    // cout << cnt << '\n';
    for(int i = 0; i < m; i ++) {
    	if(cnt == 0) {
    		cout << "Yes\n";
    	}
    	else {
    		cout << "No\n";
    	}
    	if(s[i] != t[i] && s[i] != '?' && t[i] != '?') {
            cnt ++;
        }
    	if(s[n-m+i] != t[i] && s[n-m+i] != '?' && t[i] != '?') {
    		cnt --;
    	}
    }
    if(cnt == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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