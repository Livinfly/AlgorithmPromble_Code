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
    vector<int> a(n), b(n+1);
    a[0] = n;
    for(int i = 1; i < n; i ++) {
        if(i & 1) a[i] = n+1-a[i-1];
        else a[i] = n-a[i-1];
    }
    for(int i = 0; i < n; i ++)
        b[a[i]] = i+1;
    vector<int> p(n+1), rp(n+1);
    auto ask1 = [](int x) {
        cout << "+ " << x << endl;
        int r;
        cin >> r;
        return r;
    };
    auto ask2 = [](int i, int j) {
        cout << "? " << i << ' ' << j << endl;
        int r;
        cin >> r;
        return r;
    };
    ask1(n), ask1(n+1);
    int hh = 1, mx = 0, tt = 1;
    for(int i = 2; i <= n; i ++) {
        int t = ask2(hh, i);
        if(t > mx) tt = i, mx = t;
    }
    hh = tt;
    p[hh] = a[0], rp[hh] = a[n-1];
    for(int i = 1; i <= n; i ++) {
        if(i != hh) {
            int t = ask2(hh, i);
            p[i] = a[t], rp[i] = a[n-1-t];
        }
    }
    auto answer = [&]() {
        cout << "! ";
        for(int i = 1; i <= n; i ++)
            cout << p[i] << ' ';
        for(int i = 1; i <= n; i ++)
            cout << rp[i] << ' ';
        cout << endl;
        int r;
        cin >> r;
        return r;
    };
    answer();
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