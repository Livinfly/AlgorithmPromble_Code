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
    string s;
    cin >> n >> s;
    bool okR, okB;
    okR = okB = false;
    for(auto x : s) {
        if(x == 'W') {
            if(okR ^ okB) {
                cout << "NO\n";
                return;
            }
            okR = okB = false;
        }
        else {
            if(x == 'R') okR = true;
            else if(x == 'B') okB = true;
        }
    }
    if(okR ^ okB) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}