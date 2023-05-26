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
   	vector<array<int, 3>> a(n);
    for(auto &v : a) {
        for(auto &x : v) {
            x = 1;
        }
    }
    int cur = 0;
    for(int i = 0; i < 3*n-3; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        if(v != 1 && !a[u][1]) break;
        if(v == 1 && !(a[u][0]*a[u][2])) break;
        a[u][v] = 0;
        cur ^= 1;
    }
    if(cur) {
        cout << "Sheauhaw\n";
    }
    else {
        cout << "Nocriz\n";
    }
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