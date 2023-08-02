#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct Rec {
    LL x, y;
    bool operator < (const Rec &rhs) const {
        return y - x > rhs.y - rhs.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Rec> p(n);
    priority_queue<Rec> heap;
    for(auto &t : p) {
        auto &[x, y] = t;
        cin >> x >> y;
        heap.push(t);
    }
    LL ans = 0;
    bool cur = false;
    
    while(heap.size()) {
        auto u = heap.top();
        auto [x, y] = u;
        heap.pop();
        if(cur) {
            ans += x;
            // cerr << x << '\n';
        }
        else {
            heap.push({y, x});
        }
        cur = !cur;
    }
    cout << ans << '\n';
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