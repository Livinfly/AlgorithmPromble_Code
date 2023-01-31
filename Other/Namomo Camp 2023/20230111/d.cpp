#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<double, double> PDD;

void solve() {
    PDD p[2];
    double r[2];
    for(int i = 0; i < 2; i ++)
        cin >> p[i].fi >> p[i].se >> r[i];
    double x = (p[0].fi*r[1]+p[1].fi*r[0]) / (r[0]+r[1]);
    double y = (p[0].se*r[1]+p[1].se*r[0]) / (r[0]+r[1]);
    cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}