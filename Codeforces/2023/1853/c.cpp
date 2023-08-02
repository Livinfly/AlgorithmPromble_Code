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
    vector<int> a(n+2);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    LL p = 1, INF = 1e18;
    a[0] = 1;
    a[n+1] = a[n]+2;
    // cerr << "----\n";
    while(k --) {
        int l = 0, r = n;
        while(l < r) {
            int mid = l+r+1 >> 1;
            if(a[mid]-mid < p) l = mid;
            else r = mid-1;
        }
        // cerr << r << '\n';
        if(p >= a[n]) p += n;
        else p = a[r] + (p - (a[r]-r));
        // cerr << p << '\n';
    }
    // cerr << "----\n";
    cout << p << '\n';
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