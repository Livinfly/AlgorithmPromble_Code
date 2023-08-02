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

const int N = 2e5+10;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(all(a));
    if(a[0] != 1) {
        cout << "No\n";
        return;
    }
    LL sum = a[0];
    // ori: [1, sum], x \in [1, sum] => new: [1, sum+x]
    for(int i = 1; i < n; i ++) {
        if(sum < a[i]) {
            cout << "No\n";
            return;
        }
        sum += a[i];
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