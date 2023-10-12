// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

int n, m;
vector<tuple<int, string, string>> rec;
map<int, int> mp;

int dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, (1<<n)-1});
    mp[(1<<n)-1] = 0;
    while(!heap.empty()) {
        auto [cost, cur] = heap.top(); heap.pop();
        if(!cur) break;
        // cerr << cost << ' ' << cur << ' ' << (1<<n)-1 << '\n';
        for(auto [x, s1, s2]: rec) {
            bool ok = true;
            for(int i = 0; i < n; i ++) {
                if(s1[i] == '-' && (cur >> i & 1) || s1[i] == '+' && !(cur >> i & 1)) {
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            int nxt = cur, nxtcost = cost + x;
            for(int i = 0; i < n; i ++) {
                if(s2[i] == '-' && (cur >> i & 1)) nxt -= (1 << i);
                if(s2[i] == '+') nxt |= (1 << i); 
            }

            if(!mp.count(nxt) || mp[nxt] > nxtcost) {
                mp[nxt] = nxtcost;
                heap.push({nxtcost, nxt});
            }
        }
    }
    return mp[0];
}
void solve() {
    cin >> n >> m;
    rec.resize(m);
    for(auto &[x, u, v]: rec) cin >> x >> u >> v;
    cout << dijkstra() << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}