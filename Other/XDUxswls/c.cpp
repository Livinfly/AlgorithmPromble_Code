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
    int n;
    cin >> n;
    vector<int> a(n), b, c;
    for(auto &x : a) cin >> x;
    sort(all(a), less<int>());
    b.push_back(a[0]), c.push_back(a[0]);
    for(int i = 1; i < n; i ++) {
        if(i & 1) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    LL res = b.back()*c.back();
    for(int i = 1; i < b.size(); i ++)
        res += b[i]*b[i-1];
    for(int i = 1; i < c.size(); i ++)
        res += c[i]*c[i-1];
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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