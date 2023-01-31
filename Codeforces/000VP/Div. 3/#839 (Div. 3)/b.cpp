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
    vector<int> a(4);
    int mn = 110, mx = 0;
    for(int &x : a)
        scanf("%d", &x) , mn = min(mn, x), mx = max(mx, x);
    for(int i = 0; i < 2; i ++) {
        int x = a[i], y = a[3-i];
        if(x > y) swap(x, y);
        if(mn == x && mx == y) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    scanf("%d", &Tcase); // cin >> Tcase;
    while (Tcase--) 
        solve();
    return 0;
}