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

void solve() {
    int n; cin >> n;
    vector<string> S(n), T(n);
    for(auto &s: S) cin >> s;
    for(auto &s: T) cin >> s;

    auto mapping = [&](vector<string> &s) {
        int X = n, Y = n;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(s[i][j] == '#') {
                    X = min(X, i), Y = min(Y, j);
                }
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(i+X < n && j+Y < n) s[i][j] = s[i+X][j+Y];
                else s[i][j] = '.';
            }
        }
    };
    auto rotate = [&](vector<string> &s) {
        vector<string> t(n);
        for(int i = 0; i < n; i ++) {
            t[i].resize(n);
            for(int j = 0; j < n; j ++) {
                t[i][j] = s[n-j-1][i];
            }
        }
        s = t;
    };

    mapping(S), mapping(T);

    for(int i = 0; i < 4; i ++) {
        bool ok = true;
        for(int i = 0; i < n; i ++) {
            if(S[i] != T[i]) ok = false;
        }
        if(ok) {
            cout << "Yes\n";
            return;
        }
        rotate(S);
        mapping(S);
    }
    cout << "No\n";
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}