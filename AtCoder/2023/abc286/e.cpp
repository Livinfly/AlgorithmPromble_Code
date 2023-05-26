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
	const int INF = 0x3f3f3f3f;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    vector<vector<int>> g(n, vector<int> (n, INF));
    vector<vector<LL>> val(n, vector<LL> (n, 0));
    for(int i = 0; i < n; i ++) {
    	val[i][i] = a[i];
    	string s;
    	cin >> s;
    	for(int j = 0; j < n; j ++) {
    		if(s[j] == 'Y') {
    			g[i][j] = 1;
    			val[i][j] = a[i]+a[j];
    		}
    	}
    	g[i][i] = 0;
    }
    for(int k = 0; k < n; k ++) {
    	for(int i = 0; i < n; i ++) {
    		for(int j = 0; j < n; j ++) {
    			if(g[i][k] + g[k][j] < g[i][j] || 
    				g[i][k] + g[k][j] == g[i][j] && val[i][k] + val[k][j] - a[k] > val[i][j]) {
    				g[i][j] = g[i][k] + g[k][j];
    				val[i][j] = val[i][k] + val[k][j] - a[k];
    			}
    		}
    	}
    }
    int Q;
    cin >> Q;
    while(Q --) {
    	int S, T;
    	cin >> S >> T;
        S --, T --;
    	if(g[S][T] != INF) {
    		cout << g[S][T] << ' ' << val[S][T] << '\n';
    	}
    	else {
    		cout << "Impossible\n";
    	}
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