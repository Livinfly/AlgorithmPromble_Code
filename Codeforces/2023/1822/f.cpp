#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

vector<int> e[N];
LL n, k, c;
LL mxd[N];

void solve() {
    cin >> n >> k >> c;
    for(int i = 1; i < n; i ++) {
    	int a, b;
    	cin >> a >> b;
    	e[a].push_back(b);
    	e[b].push_back(a);
    }
    int mx1 = 0, mx2 = 0;
    
    for(int i = 1; i <= n; i ++)
    	dep[i] = -1;
    dep[1] = 0;
   	while(q.size()) {
   		auto u = q.front(); 
   		q.pop();
   		for(auto v : e[u]) {
   			if(!~dep[v]) {
   				dep[v] = dep[u]+1;
   				q.push(v);
   			}
   		}
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