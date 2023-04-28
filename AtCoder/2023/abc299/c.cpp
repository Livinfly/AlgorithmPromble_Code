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
    int res = -1, cnt = 0;
    for(int i = 0; i < n; i ++) {
    	if(s[i] == 'o') cnt ++;
    	else res = max(res, cnt), cnt = 0;
    }
    cnt = 0;
    for(int i = n-1; i >= 0; i --) {
    	if(s[i] == 'o') cnt ++;
    	else res = max(res, cnt), cnt = 0;
    }
    if(res == 0) res = -1;
    cout << res << '\n';
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