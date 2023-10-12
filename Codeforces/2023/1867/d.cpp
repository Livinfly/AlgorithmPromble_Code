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
    int n, k; cin >> n >> k;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    if(k == 1) {
        for(int i = 1; i <= n; i ++) {
            if(b[i] != i) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i ++) {
        int j = i;
        while(!vis[j]) {
            vis[j] = i;
            j = b[j];
        }
        if(vis[j] == i) {
            int x = j, len = 0;
            do {
                x = b[x], len++;
            } while(x != j);
            if(len != k) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}