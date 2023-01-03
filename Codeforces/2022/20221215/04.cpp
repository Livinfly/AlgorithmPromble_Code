#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int ask(int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}
void solve() {
    int n;
    cin >> n;
    int x = 1, y = 2;
    for(int i = 3; i <= n; i ++) {
        int tx = ask(x, i), ty = ask(y, i);
        if(tx == ty) continue;
        if(tx > ty) 
            y = i;
        else 
            x = i;
    }
    cout << "! " << x << ' ' << y << '\n';
    cout.flush();
    int res;
    cin >> res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}