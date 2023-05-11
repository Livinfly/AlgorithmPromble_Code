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
    vector<int> s(m+2), rs(m+2);
    int cntl = 0, cntr = 0, cnt = 0;
    for(int i = 1; i <= m; i ++)
    	s[i] = rs[i] = 1;
    for(int i = 0; i < n; i ++) {
    	int x;
    	cin >> x;
        if(x < 0) {
            if(x == -1) cntl ++;
            else cntr ++;
            continue;
        }
    	s[x] --, rs[x] --;
    }
    for(int i = 1; i <= m; i ++) {
        if(s[i] <= 0) cnt ++;
    	s[i] = max(s[i], 0)+s[i-1];
        // cout << s[i] << " \n"[i == m];
    }
    for(int i = m; i > 0; i --) {
    	rs[i] = max(rs[i], 0)+rs[i+1];
    }
    // for(int i = 1; i <= m; i ++)
        // cout << rs[i] << " \n"[i == m];
    int ans = cnt + max(cntl, cntr);
    for(int i = 1; i <= m; i ++) {
        if(s[i] == s[i-1])
		  ans = max(ans, min(cntl, s[i-1]) + min(cntr, rs[i+1]) + cnt);
    }
    cout << min(ans, m) << '\n';
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