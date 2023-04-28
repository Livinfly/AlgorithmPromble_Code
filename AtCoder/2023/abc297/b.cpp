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
    string s;
    cin >> s;
    int r = 0, b = -1;
    bool ok = true;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'R') {
            r ^= 1;
        }
        else if(s[i] == 'K') {
            if(!r) ok = false;
        }
        else if(s[i] == 'B') {
            if(b == -1) b = i;
            else if(b%2 == i%2) {
                ok = false;
                // cout << b << ' ' << i << '\n';
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}