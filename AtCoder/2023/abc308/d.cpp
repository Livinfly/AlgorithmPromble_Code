#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

string temp = "snuke";
int dxy[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<int>> d(n, vector<int>(m, -1));
    for(auto &s : g) cin >> s;
    auto bfs = [&]() {
        if(g[0][0] != temp[0]) return false;
        queue<PII> q;
        q.push({0, 0});
        d[0][0] = 0;
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++) {
                int a = x+dxy[i][0], b = y+dxy[i][1];
                if(a < 0 || a >= n || b < 0 || b >= m) continue;
                if(g[a][b] != temp[(d[x][y]+1) % 5]) continue;
                if(d[a][b] != -1) continue;
                d[a][b] = (d[x][y]+1) % 5;
                if(a == n-1 && b == m-1) return true;
                q.push({a, b});
            }
        }
        return false;
    };
    if(bfs()) {
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