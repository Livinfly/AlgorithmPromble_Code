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

void solve0() {
    int n = 3;
    for(int i = 10; i >= 0; i --) {
        vector<int> ve(n+2);
        ve[n+1] = i;
        for(int j = n; j >= 1; j --) {
            ve[j] = ve[j+1]%j;
        }
        for(int j = 1; j <= n+1; j ++) {
            cerr << ve[j] << " \n"[j==n+1];
        }
    }
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    if(k > 3) {
        cout << "0\n";
        return;
    }
    if(k == 1) {
        cout << 1 << '\n';
    }
    else if(k == 2) {
        cout << min(n-1, m) + m/n << '\n';
    }
    else if(k == 3) {
        cout << m+1 - 1 - (min(n-1, m) + m/n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    
    // solve0();
    // cerr << '\n';

    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}