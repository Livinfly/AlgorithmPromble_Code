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
    vector<PII> segs(n);
    for(auto &[l, r]: segs) cin >> l >> r;
    sort(all(segs));
    int i = 0, p = 1;
    priority_queue<int, vector<int>, greater<int>> heap;
    while(i < n || !heap.empty()) {
        while(i < n && segs[i].fi == p) heap.push(segs[i++].se);
        if(heap.empty()) {
            p = segs[i].fi;
            continue;
        }
        if(p > heap.top()) {
            cout << "No\n";
            return;
        }
        heap.pop();
        p++;
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}