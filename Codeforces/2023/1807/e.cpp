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

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), s(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    auto ask = [](int x) {
        cout << "? ";
        cout << x << ' ';
        for(int i = 1; i <= x; i ++) {
            cout << i << " \n"[i==x];
        }
        cout.flush();
    };
    auto check = [&](int mid) {
        ask(mid);
        int ret; cin >> ret;
        return s[mid] == ret;
    };
    int l = 1, r = n;
    while(l < r) {
        int mid = l+r >> 1;
        if(check(mid)) l = mid+1;
        else r = mid;
    }
    cout << "! " << r << '\n';
    cout.flush();
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