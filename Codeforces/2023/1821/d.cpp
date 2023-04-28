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

int n, k;

void solve() {
    cin >> n >> k;
    vector<int> l(n), r(n);
    for(auto &x : l) cin >> x;
    for(auto &x : r) cin >> x;
    int res = 2e9, sum = 0;
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i ++) {
        sum += r[i]-l[i]+1;
        heap.push(r[i]-l[i]+1);
        while(sum >= k) { // while
            int t = l[i]-1 + k-(sum-(r[i]-l[i]+1));
            res = min(res, t+2*(int)heap.size());
            sum -= heap.top();
            heap.pop();
        }
    }
    if(res == 2e9) res = -1;

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}