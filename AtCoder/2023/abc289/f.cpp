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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((sx-tx)%2 || (sy-ty)%2) {
        cout << "No\n";
        return;
    }
    // just solve one direction
    if((a == b && sx != tx) || (c == d && sy != ty)) { 
        sx = 2*a-sx, sy = 2*c-sy;
        if((a == b && sx != tx) || (c == d && sy != ty)) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n" << a << " " << c << '\n';
    }
    else cout << "Yes\n";
    while(sx < tx) {
        cout << a << ' ' << c << '\n' << a+1 << ' ' << c << '\n';
        sx += 2;
    }
    while(sx > tx) {
        cout << a+1 << ' ' << c << '\n' << a << ' ' << c << '\n';
        sx -= 2;
    }
    while(sy < ty) {
        cout << a << ' ' << c << '\n' << a << ' ' << c+1 << '\n';
        sy += 2;
    }
    while(sy > ty) {
        cout << a << ' ' << c+1 << '\n' << a  << ' ' << c << '\n';
        sy -= 2;
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