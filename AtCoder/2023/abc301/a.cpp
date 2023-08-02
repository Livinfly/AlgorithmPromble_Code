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
    int cur = 0, cnt = 0;
    for(auto x : s) {
    	if(x == 'T') {
    		cnt ++;
    	}
    	else {
    		cnt --;
    	}
    	if(cnt > 0) cur = 0;
    	else if(cnt < 0) cur = 1;
    }
    if(!cur) {
    	cout << "T\n";
    }
    else {
    	cout << "A\n";
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