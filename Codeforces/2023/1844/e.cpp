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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<PII>> e(n+m-2);
    while(k --) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        a1 --, a2 --, b1 --, b2 --;
        if(b1 < b2) {
            e[a1].emplace_back(n-1+b1, 1);
            e[n-1+b1].emplace_back(a1, 1);
        }
        else {
            e[a1].emplace_back(n-1+b2, 0);
            e[n-1+b2].emplace_back(a1, 0);
        }
    }
    vector<int> c(n+m-2, -1);
    for(int i = 0; i < n+m-2; i ++) {
        if(c[i] == -1) {
            c[i] = 0;
            queue<int> q;
            q.push(i);
            while(q.size()) {
                auto u = q.front();
                q.pop();
                for(auto [v, w] : e[u]) {
                    if(c[v] == -1) {
                        c[v] = c[u] ^ w;
                        q.push(v);
                    }
                    else if(c[v] != c[u] ^ w) {
                        cout << "No\n";
                        return;
                    }
                }

            }
        }
    }
    cout << "Yes\n";
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