// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const db eps = 1e-8;

PII s, p, a, b;

db dist(PII a, PII b) {
    return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se);
}
bool distCheck(PII a, PII b, db mid) {
    return dist(a, b) <= mid*mid;
}
bool check(db mid) {
    if(distCheck(p, a, mid) && distCheck(s, a, mid)) return true;
    if(distCheck(p, b, mid) && distCheck(s, b, mid)) return true;
    bool f1 = distCheck(p, a, mid) || distCheck(p, b, mid);
    bool f2 = distCheck(s, a, mid) || distCheck(s, b, mid);
    bool f3 = sqrt(dist(a, b)) <= 2*mid;
    return f1 && f2 && f3;
}
void solve() {
    db l = 0, r = 1e6;
    cin >> p.fi >> p.se;
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;
    while(r-l > eps) {
        db mid = (l+r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20); // double
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