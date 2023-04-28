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
    for(auto &x : a) {
        cin >> x;
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int i;
    for(i = 0; i < min(k, (int)a.size()); i ++) {
        if(a[i] != i) {
            cout << i << '\n';
            return;
        }
    }
    if(i == min(k, (int)a.size())) {
        cout << i << '\n';
        return;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}