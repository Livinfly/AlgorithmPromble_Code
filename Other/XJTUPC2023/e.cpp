#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

double read() {
    int f = 1;
    char ch = cin.get(); // getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        if(ch == '+' || ch == '-') break;
        ch = cin.get(); // getchar();
    }
    double x;
    cin >> x;
    return x*f;
}
void solve() {
    int n;
    cin >> n;
    double b = read();
    vector<vector<double>> g(n, vector<double>(n));
    for(auto &v : g)
    	for(auto &x : v) 
    		x = read();
    if(n == 1) {
    	cout << "kono jinsei, imi ga nai!\n";
    	return;
    }
    vector<bool> vis;
    auto bfs = [&](int u) {
        queue<int> q;
        q.push(u);
        vis[u] = true;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int x = -1;
            for(int i = 0; i < n; i ++) {
                if(i != t && g[t][i] >= b && (x == -1 || g[t][x] < g[t][i])) {
                    x = i;
                }
            }
            if(x == -1) continue;
            if(x == u) return true;
            if(!vis[x]) {
                vis[x] = true;
                q.push(x);
            }
        }
        return false;
    };
    for(int i = 0; i < n; i ++) {
        vis.assign(n, false);
        if(!bfs(i)) {
            cout << "hbxql\n";
            return;
        }
    }
    cout << "wish you the best in your search\n";
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