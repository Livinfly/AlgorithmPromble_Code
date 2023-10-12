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

void solve() {
    int n; cin >> n;
    vector<PII> p(n);
    for(auto &[x, y]: p) cin >> x >> y;
    sort(all(p));
    // 只需要记前面的最大最小值，因为后面加进来的时候配对还是完全的。
    
    auto check = [&](int mid) {
        queue<PII> q;
        q.push(p[0]);
        int mn = 1e9, mx = -1e9;
        for(int i = 1; i < n; i ++) {
            auto [x, y] = p[i];
            while(!q.empty() && x-q.front().fi >= mid) {
                int yy = q.front().se;
                mn = min(mn, yy), mx = max(mx, yy);
                q.pop();
            }
            q.push(p[i]);
            if(y - mn >= mid || mx - y >= mid) return true;
        }
        return false;
    };

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l+r+1 >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << r << '\n';
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