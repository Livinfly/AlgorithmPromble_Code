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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int p = -1, q = -1;
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] == a[0]) cnt++;
        if(cnt == k) {
            p = i;
            break;
        }
    }
    // cerr << p << ' ' << q << '\n';
    cnt = 0;
    for(int i = n-1; i >= 0; i --) {
        if(a[i] == a[n-1]) cnt++;
        if(cnt == k) {
            q = i;
            break;
        }
    }
    // cerr << p << ' ' << q << '\n';
    if(a[0] == a[n-1] && p != -1 || p != -1 && q != -1 && p < q) {
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}