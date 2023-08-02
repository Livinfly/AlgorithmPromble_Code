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
    string S, T;
    cin >> S >> T;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
    	a[i] = (T[i] - S[i] + 26) % 26;
    	// cerr << a[i] << " \n"[i+1 == n];
    }
    b[0] = a[0]; // ..
    for(int i = 1; i < n; i ++) {
        b[i] = (a[i] - a[i-1] + 26) % 26;
        // cerr << b[i] << " \n"[i+1 == n];
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(b[i] != 0) {
            ans ++; 
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}