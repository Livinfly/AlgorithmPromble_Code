#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int n;
int a[N][N], ta[N][N], b[N][N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
    	for(int j = 1; j <= n; j ++)
    		cin >> a[i][j];
    for(int i = 1; i <= n; i ++)
    	for(int j = 1; j <= n; j ++)
    		cin >> b[i][j];
    auto rotate = [](int a[N][N]) {
    	for(int i = 1; i <= n; i ++)
    		for(int j = 1; j <= n; j ++)
    			ta[i][j] = a[n+1-j][i];
    	memcpy(a, ta, sizeof ta);
    	return;
    };
    auto check = [&]() {
    	for(int i = 1; i <= n; i ++)
    		for(int j = 1; j <= n; j ++)
    			if(a[i][j] == 1) {
    				if(b[i][j] != 1) return false;
    			}
    	return true;
    };
    int cnt = 0;
    while(cnt < 4 && !check()) {
    	rotate(a);
    	cnt ++;
    }
    if(cnt < 4) cout << "Yes\n";
    else cout << "No\n";
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